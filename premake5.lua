workspace "MOB_Engine"
    architecture "x64"
    startproject "SandboxTest"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Mob_Engine"
    location "Mob_Engine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/Libraries/**.h",
        "%{prj.name}/Libraries/**.lib",
        "%{prj.name}/**.dll"
    }

    includedirs {
        "%{prj.name}/Libraries/SDL2-2.0.12/include"
    }

    libdirs{
        "%{prj.name}/Libraries/SDL2-2.0.12/lib/x64"
    }

    links{
        "SDL2",
        "SDL2main",
        "SDL2_image"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
            "MOB_DLL_EXPORT"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandboxTest")
        }

    filter "configurations:Debug"
        defines "MOB_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "MOB_RELEASE"
        optimize "On"
        buildoptions "/MD"

project "SandboxTest"
    location "SandboxTest"
    kind "ConsoleApp"

    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/**.h",
        "%{prj.name}/**.cpp",
        "%{prj.name}/Libraries/**.h",
        "%{prj.name}/Libraries/**.lib",
        "%{prj.name}/**.dll"
    }

    includedirs {
        "Mob_Engine/Libraries/SDL2-2.0.12/include",
        "Mob_Engine/src"
    }

    libdirs{
        "Mob_Engine/Libraries/SDL2-2.0.12/lib/x64"
    }

    links{
        "Mob_Engine",
        "SDL2",
        "SDL2main",
        "SDL2_image"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        defines "MOB_DEBUG"
        symbols "On"
        buildoptions "/MDd"

    filter "configurations:Release"
        defines "MOB_RELEASE"
        optimize "On"
        buildoptions "/MD"
    