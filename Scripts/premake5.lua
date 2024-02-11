-- premake5.lua
workspace "CxxMemory"
    location "../Build"
    configurations {"Debug", "Release"}
    platforms {"Static_x86", "Static_x64", "UnitTest_x86", "UnitTest_x64"}

project "CxxMemory"
    kind "ConsoleApp"
    language "C++"
    targetdir "../Build/Binaries/%{cfg.buildcfg}"
    cppdialect "C++17"

    -- .cpp, .inl, and .h files only.
    files {
        "../Workspace/Source/**.cpp",
        "../Workspace/Include/**.h",
        "../Workspace/Include/**.inl",
    }

    includedirs {
        "../Workspace/Include",
    }

    -- Miscilaneous files.
    files {
        "../**.gitignore",
        "../**.licenseheader",
        "../**.md",
        "../Scripts/**.lua",
    }

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"

    filter "platforms:Static_x86"
        kind "StaticLib"
        architecture "x86"

    filter "platforms:Static_x64"
        kind "StaticLib"
        architecture "x86_64"

    -- Unit Testing
    filter "platforms:UnitTest_x86"
        kind "ConsoleApp"
        architecture "x86"
        defines {"CXX_MEMORY_UNIT_TEST"}

    filter "platforms:UnitTest_x64"
        kind "ConsoleApp"
        architecture "x86_64"
        defines {"CXX_MEMORY_UNIT_TEST"}