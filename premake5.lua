workspace "MouseGame"
configurations { "Debug", "Release", "Dist" }
architecture "x64"

local SFML_ROOT = "Dependencies/SFML-2.6.1"
local SFML_BUILD = "Dependencies/SFML-2.6.1/build"
-- Dist builds SFML as Release
local SFML_CFG = "%{cfg.buildcfg == 'Debug' and 'Debug' or 'Release'}"

local SFML_EXTRA_ARGS = ""
if os.target() == "windows" then
	SFML_EXTRA_ARGS = " -DOPENAL_INCLUDE_DIR=\"%{wks.location}/" .. SFML_ROOT .. "/extlibs/headers/AL\""
end

project "SFML"
	kind "Makefile"

	buildcommands {
		"cmake -S " .. SFML_ROOT .. " -B " .. SFML_BUILD .. " -DCMAKE_BUILD_TYPE=" .. SFML_CFG .. " -DBUILD_SHARED_LIBS=OFF -DSFML_BUILD_EXAMPLES=OFF -DSFML_BUILD_DOC=OFF -DSFML_INSTALL_PKGCONFIG_FILES=OFF" .. SFML_EXTRA_ARGS,
		"cmake --build " .. SFML_BUILD .. " --config " .. SFML_CFG .. " --parallel"
	}
	cleancommands {
		"cmake --build " .. SFML_BUILD .. " --target clean"
	}

	filter "system:windows"
		buildoutputs { SFML_BUILD .. "/lib/" .. SFML_CFG .. "/sfml-system-s%{cfg.buildcfg == 'Debug' and '-d' or ''}.lib" }

	filter "system:linux"
		buildoutputs { SFML_BUILD .. "/lib/libsfml-system-s.a" }

project "MouseGame"
	kind "ConsoleApp"
	language "C++"
    cppdialect "C++17"

	OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"
	targetdir("build/" .. OutputDir .. "/")
	objdir("build/Intermediates" .. OutputDir .. "/")

	dependson { "SFML" }

	postbuildcommands { "{COPYDIR} Assets %{cfg.targetdir}/Assets" }


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

	filter "system:windows"
		libdirs {
			SFML_BUILD .. "/lib/" .. SFML_CFG,
			SFML_ROOT .. "/extlibs/libs-msvc-universal/x64"
		}

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