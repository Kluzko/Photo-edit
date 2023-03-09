-- Include conan generate script
include("conanbuildinfo.premake.lua")
-- Script for cleaning workspace
include("cleanWorkspace.lua")



-- Main Workspace
workspace "ImageEditor"
    -- Import conan generate config
    conan_basic_setup()

    -- Project
    project "ImageEditorApp"
        kind "ConsoleApp"
        language "C++"
        targetdir "bin/%{cfg.buildcfg}"
		objdir "bin/%{cfg.buildcfg}/obj/"
		location "src"
        debugdir "app"

        linkoptions { conan_exelinkflags }

        files { "src/**.cpp","src/**.h","bindings/*.cpp", "bindings/*.h" }
        includedirs { "./bindings"}

        filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

		filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
     -- Tests
    project "ImageEditorTest"
        kind "ConsoleApp"
        language "C++"
        targetdir "bin/%{cfg.buildcfg}"
        objdir "bin/%{cfg.buildcfg}/obj/"
        location "tests"
        debugdir "app"
        linkoptions { conan_exelinkflags }
        links { "ImageEditorApp" }
    
        -- Add test files
        files { "tests/*.cpp" }
        files { "src/**.cpp","src/**.h","bindings/*.cpp", "bindings/*.h" }
        
        includedirs { "./bindings","./src" }

        -- We can also configure Catch through defines
	    defines "CATCH_CPP11_OR_GREATER"

        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "On"



