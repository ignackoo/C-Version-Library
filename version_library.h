/******************************************************************************
**  Copyright(c) 2022 ignackoo. All rights reserved.
**
**  Licensed under the MIT license.
**  See LICENSE file in the project root for full license information.
**
**  This file is part of the C Version Libray.
**
**  Library build name and version
**
**  defined according to c# .net applications and library
**  build version definition ... as ... major, minor, build, revision
**  major    = int      ... user defined major ver and is user incremental
**  minor    = int      ... user defined minor ver and is user incremental
**  build    = __DATE__ ... autoincrement __DATE__ ver of build in form ("Mmm dd yyyy")
**  revision = __TIME__ ... autoincrement __TIME__ ver of build in form ("hh:mm:ss")
**
*/
#ifndef __VERSION_LIBRARY_H
#define __VERSION_LIBRARY_H


#ifdef __cplusplus
extern "C" {
#endif

    /* name */
    char* Version_GetName(void);

    /* library version buid specification */
    unsigned long Version_GetMajor(void);

    unsigned long Version_GetMinor(void);

    unsigned long Version_GetBuild(void);

    unsigned long Version_GetRevision(void);

#ifdef __cplusplus
}
#endif


#endif /* __VERSION_LIBRARY_H */
