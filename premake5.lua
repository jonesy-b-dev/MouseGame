workspace "MouseGame"
configurations { "Debug", "Release", "Dist" }
architecture "x64"

local SFML_ROOT = "Dependencies/SFML-2.6.1"
local SFML_BUILD = "Dependencies/SFML-2.6.1/build"

project "SFML"
	kind "Makefile"

	-- CMake configure + build, runs before anything else
	buildcommands {
		-- Configure
		"cmake -S " .. SFML_ROOT .. " -B " .. SFML_BUILD .. " -DCMAKE_BUILD_TYPE=%{cfg.buildcfg} -DBUILD_SHARED_LIBS=OFF -DSFML_BUILD_EXAMPLES=OFF -DSFML_BUILD_DOC=OFF",
		-- Build
		"cmake --build " .. SFML_BUILD .. " --config %{cfg.buildcfg} --parallel"
	}
	-- Makefile projects need a "clean" command too
	cleancommands {
		"cmake --build " .. SFML_BUILD .. " --target clean"
	}
	-- Dummy output so premake knows when to re-run
	buildoutputs { SFML_BUILD .. "/lib/libsfml-system-s.a" }

project "MouseGame"
	kind "ConsoleApp"
	language "C++"
    cppdialect "C++17"

	OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"
	targetdir("build/" .. OutputDir .. "/")
	objdir("build/Intermediates" .. OutputDir .. "/")

	dependson { "SFML" }

	files {
		"Source/**.h",
		"Source/**.hpp",
		"Source/**.c",
		"Source/**.cpp"
	}

	includedirs {
		SFML_ROOT .. "/include",
		-- Engine headers
		"Source/Engine"
	}

	defines { "SFML_STATIC" }

	libdirs { SFML_BUILD .. "/lib" }

	-- Platform specific links
    filter "system:windows"
        systemversion "latest"
        defines { "GAME_PLATFORM_WINDOWS" }
        links {
            "opengl32", "freetype", "winmm",
            "gdi32", "openal32", "flac",
            "vorbisenc", "vorbisfile", "vorbis",
            "ogg", "ws2_32",
        }

    filter "system:linux"
        defines { "GAME_PLATFORM_LINUX" }
        links {
            "GL", "X11", "Xrandr", "Xi",
            "freetype", "udev", "openal",
            "FLAC", "Xcursor", "vorbisenc", "vorbisfile",
            "vorbis", "ogg", "pthread",
        }

	-- Settings for different build modes

	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "On"
		links {
			"sfml-audio-s-d",
			"sfml-graphics-s-d",
			"sfml-network-s-d",
			"sfml-window-s-d",
			"sfml-system-s-d",
		}

		postbuildcommands {
			'{COPYDIR} "%{wks.location}Assets" "%{cfg.targetdir}/Assets"',
		}

	filter "configurations:Release"
		defines { "RELEASE", "ST_PLATFORM_WINDOWS" }
		runtime "Release"
		optimize "On"
		symbols "On"
		links {
			"sfml-audio-s",
			"sfml-graphics-s",
			"sfml-network-s",
			"sfml-window-s",
			"sfml-system-s",
		}

		postbuildcommands {
			'{COPYDIR} "%{wks.location}Assets" "%{cfg.targetdir}/Assets"',
		}

	filter "configurations:Dist"
		defines { "DIST", "ST_PLATFORM_WINDOWS" }
		runtime "Release"
		optimize "On"
		symbols "Off"
	    links {
			"sfml-audio-s",
			"sfml-graphics-s",
			"sfml-network-s",
			"sfml-window-s",
			"sfml-system-s",
		}

		postbuildcommands {
			'{COPYDIR} "%{wks.location}Assets" "%{cfg.targetdir}/Assets"',
		}
