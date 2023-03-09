.PHONY: clean debug realise test 

PREMAKE := vendor/premake/premake5

clean:
	$(PREMAKE) clean

realise:
	conan install . --build missing -pr:b=default
	$(PREMAKE) vs2022

debug:
	conan install . --build missing -s build_type=Debug
	$(PREMAKE) vs2022

test:
	.\bin\Debug\ImageEditorTest.exe