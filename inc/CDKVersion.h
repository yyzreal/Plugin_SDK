/* Plugin SDK - for licensing and copyright see license.txt */

#pragma once

#include "EngineVersion.h"

#if USE_NEW_INCLUDE_PATHS
#include <CryRenderer/IRenderer.h>
#include <Cry3DEngine/I3DEngine.h>
#else
#include <IRenderer.h>
#include <I3DEngine.h>
#endif

/* for reuse of compiled CRYENGINE SDK version (its not defined in CDK directly so we have to do it ourself) */
#if defined(CDK_VERSION_DETERMINED)
// Do nothing since the version was determined by prebuilt events (this was required because in 3.4.5 there was no usable difference)
// So the Version is now determined using Bin32/CrySystem.dll

#elif defined(MAX_NUM_VIEWPORTS)
#define CDK_VERSION 354
#define PLUGIN_COMPILED_CDK_VERSION "3.5.4"

#elif defined(DEFAULT_SID)
#define CDK_VERSION 344
#define PLUGIN_COMPILED_CDK_VERSION "3.4.4"

#elif defined(FRT_CLEAR_RESET_VIEWPORT)
#define CDK_VERSION 343
#define PLUGIN_COMPILED_CDK_VERSION "3.4.3"

#elif defined(R_DX11_RENDERER)
#define CDK_VERSION 340
#define PLUGIN_COMPILED_CDK_VERSION "3.4.0"

#else
#define CDK_VERSION 339
#define PLUGIN_COMPILED_CDK_VERSION "3.3.9"

#endif

/* make some defines for backward/forward compatibility */
#if CDK_VERSION < 344 || CDK_VERSION >= 350

#if USE_NEW_INCLUDE_PATHS
#include <CryFlowGraph/IFlowSystem.h>
#else
#include <IFlowSystem.h>
#endif

ILINE SOutputPortConfig OutputPortConfig_Null()
{
    ScopedSwitchToGlobalHeap useGlobalHeap;
    SOutputPortConfig result = {NULL, NULL, NULL, 0};
    return result;
}

ILINE SInputPortConfig InputPortConfig_Null()
{
    ScopedSwitchToGlobalHeap useGlobalHeap;
    SInputPortConfig result = {NULL, NULL, NULL, NULL, TFlowInputData( 0, false )};
    return result;
}
#endif

#if CDK_VERSION < 340
#define VIRTUAL_SCREEN_WIDTH 800.0f //!< Width of the virtual screen, inside the plugin relative sizes are used.
#define VIRTUAL_SCREEN_HEIGHT 600.0f //!< Height of the virtual screen, inside the plugin relative sizes are used.
#endif

#if CDK_VERSION >= 350
#define eFLPriority_Default FRAMEWORKLISTENERPRIORITY_DEFAULT
#define eFLPriority_Menu FRAMEWORKLISTENERPRIORITY_MENU

#ifndef MAX_PLAYER_LIMIT
#if CDK_VERSION < 500
#include <ICrysis3Lobby.h>
#endif

#define MAX_PLAYER_LIMIT DETAILED_SESSION_MAX_PLAYERS
#endif

#ifndef CrySharedLibrayExtension
#define CrySharedLibrayExtension CrySharedLibraryExtension
#endif

#ifndef ESYSTEM_EVENT_SHUTDOWN
#define ESYSTEM_EVENT_SHUTDOWN ESYSTEM_EVENT_FULL_SHUTDOWN
#endif

#endif