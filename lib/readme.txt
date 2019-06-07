An optional directory where you put portability-related source code. This is
mainly replacement implementation for system calls that are unavailable on some
systems. You can also put tools here that you commonly use across many different
packages, tools that are too simple to just make libraries out of every one of
them. Common files encountered here are files that replace system calls to the
GNU C library that are not available in proprietary C libraries.
