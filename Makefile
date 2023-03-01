realise:
	conan install . --build missing -pr:b=default
	"vendor/premake/premake5" vs2022
debug:
	conan install . --build missing  -s build_type=Debug
	"vendor/premake/premake5" vs2022