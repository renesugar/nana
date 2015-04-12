/*
 *	Nana Configuration
 *	Nana C++ Library(http://www.nanapro.org)
 *	Copyright(C) 2003-2014 Jinhao(cnjinhao@hotmail.com)
 *
 *	Distributed under the Boost Software License, Version 1.0.
 *	(See accompanying file LICENSE_1_0.txt or copy at
 *	http://www.boost.org/LICENSE_1_0.txt)
 *
 *	@file: nana/config.hpp
 */

#ifndef NANA_CONFIG_HPP
#define NANA_CONFIG_HPP

//Select platform automatically
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
//Windows:
	#define NANA_WINDOWS	1
	#define PLATFORM_SPEC_HPP <nana/detail/win32/platform_spec.hpp>

	//Test if it is MINGW
	#if defined(__MINGW32__)
		#define NANA_MINGW
		#define STD_CODECVT_NOT_SUPPORTED
	#endif
#elif (defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(_CRAYC)
//Linux:
	#define NANA_LINUX	1
	#define NANA_X11	1
	#define PLATFORM_SPEC_HPP <nana/detail/linux_X11/platform_spec.hpp>
	#define STD_CODECVT_NOT_SUPPORTED
#else
#   error   "Only Windows and Unix are support now"
#endif

// C++11 detection
#if defined(__GNUC_MINOR__)
#   if __GNUC_MINOR__ < 8
#       define NANA_NO_CPP11
#   endif
#elif _MSC_VER < 1700
#   define NANA_NO_CPP11
#endif

#if defined(NANA_NO_CPP11)
#   define STD_THREAD_NOT_SUPPORTED
#endif

//Here defines some flags that tell Nana what features will be supported.

#define NANA_ENABLE_PNG
#define NANA_UNICODE    // always use unicode, don't make users confusing!

#if defined(NANA_WINDOWS)
	#ifndef _UNICODE
		#define _UNICODE
	#endif

	#ifndef UNICODE
		#define UNICODE
	#endif
#endif

#endif	//NANA_CONFIG_HPP
