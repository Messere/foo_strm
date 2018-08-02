#include "stdafx.h"

// Declaration of your component's version information
// Since foobar2000 v1.0 having at least one of these in your DLL is mandatory to let the troubleshooter tell different versions of your component apart.
// Note that it is possible to declare multiple components within one DLL, but it's strongly recommended to keep only one declaration per DLL.
// As for 1.1, the version numbers are used by the component update finder to find updates; for that to work, you must have ONLY ONE declaration per DLL. If there are multiple declarations, the component is assumed to be outdated and a version number of "0" is assumed, to overwrite the component with whatever is currently on the site assuming that it comes with proper version numbers.
DECLARE_COMPONENT_VERSION(
	"STRM support",
	"1.0",
	"Support for KODI's .strm files which are basically one item playlists that reference to external stream\n"
		"\n"
		"\n"
		"\n"
		"MIT License"
		"\n\n"
		"Copyright (c) 2018 Dariusz Sieradzki"
		"\n\n"
		"Permission is hereby granted, free of charge, to any person obtaining a copy "
		"of this software and associated documentation files (the \"Software\")\, to deal "
		"in the Software without restriction, including without limitation the rights "
		"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell "
		"copies of the Software, and to permit persons to whom the Software is "
		"furnished to do so, subject to the following conditions: "
		"\n\n"
		"The above copyright notice and this permission notice shall be included in all "
		"copies or substantial portions of the Software. "
		"\n\n"
		"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR "
		"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
		"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE "
		"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
		"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, "
		"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE "
		"SOFTWARE.\n"
);


// This will prevent users from renaming your component around (important for proper troubleshooter behaviors) or loading multiple instances of it.
VALIDATE_COMPONENT_FILENAME("foo_strm.dll");
