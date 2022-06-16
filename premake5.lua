workspace "Ravbite"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ravbite"
    location "Ravbite"
    kind "SharedLib"
    language "C++"

    targetdir ("target/bin/" .. outputDir .. "/%{prj.name}")
    objdir ("target/obj/" .. outputDir .. "/%{prj.name}")

    pchheader "rbpch.h"
    pchsource "Ravbite/src/rbpch.cpp"

    files { 
        "%{prj.name}/src/**.h", 
        "%{prj.name}/src/**.hpp", 
        "%{prj.name}/src/**.cpp" 
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines {
            "RB_PLATFORM_WINDOWS",
            "RB_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../target/bin/" .. outputDir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "RB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "RB_DIST"
        optimize "On"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("target/bin/" .. outputDir .. "/%{prj.name}")
        objdir ("target/obj/" .. outputDir .. "/%{prj.name}")
    
        files { 
            "%{prj.name}/src/**.h", 
            "%{prj.name}/src/**.hpp", 
            "%{prj.name}/src/**.cpp" 
        }
    
        includedirs {
            "Ravbite/vendor/spdlog/include",
            "Ravbite/src"
        }

        links {
            "Ravbite"
        }
    
        filter "system:windows"
            cppdialect "C++20"
            staticruntime "On"
            systemversion "latest"
    
            defines {
                "RB_PLATFORM_WINDOWS"
            }
    
        filter "configurations:Debug"
            defines "RB_DEBUG"
            symbols "On"
    
        filter "configurations:Release"
            defines "RB_RELEASE"
            optimize "On"
    
        filter "configurations:Dist"
            defines "RB_DIST"
            optimize "On"