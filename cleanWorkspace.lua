    -- Clean target
    newaction {
        trigger = "clean",
        description = "clean the software",
        execute = function ()
            print("Cleaning...")
            os.rmdir("./bin")
            os.remove("ImageEditor.sln")
            os.remove("src/ImageEditor.vcxproj")
            os.remove("src/ImageEditor.vcxproj.user")
            os.remove("src/ImageEditor.vcxproj.filters")
            os.remove("tests/ImageEditorTest.vcxproj")
            os.remove("tests/ImageEditorTest.vcxproj.user")
            print("Done.")
        end
    }