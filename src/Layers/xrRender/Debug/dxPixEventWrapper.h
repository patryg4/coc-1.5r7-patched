#ifndef dxPixEventWrapper_included
#define dxPixEventWrapper_included
#pragma once

#if defined(COC_DEBUG) && !defined(USE_OGL)

#define PIX_EVENT(Name) dxPixEventWrapper pixEvent##Name(L#Name)

class dxPixEventWrapper
{
public:
    dxPixEventWrapper(LPCWSTR wszName) { D3DPERF_BeginEvent(D3DCOLOR_RGBA(127, 0, 0, 255), wszName); }
    ~dxPixEventWrapper() { D3DPERF_EndEvent(); }
};

void dxPixSetDebugName(ID3DDeviceChild* resource, const shared_str& name);

#define SET_DEBUG_NAME(resource, name) dxPixSetDebugName(resource, name)

#else //    DEBUG

#define PIX_EVENT(Name) { }
#define SET_DEBUG_NAME(resource, name) { }

#endif //   DEBUG

#endif //   dxPixEventWrapper_included
