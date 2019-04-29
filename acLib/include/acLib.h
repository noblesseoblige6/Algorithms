#pragma once
// 
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <limits>
#include <string>
#include <memory>

#include <cmath>

#include "Constant.h"

#include "Util.h"

#include "Vec.h"
#include "Mat.h"
#include "Quaternion.h"

#include "Segment.h"
#include "Triangle.h"

#include "CGL.h"
#include "PSL.h"

#include "Loader/acModelLoader.h"
#include "Loader/acObjLoader.h"

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーから使用されていない部分を除外します。
// Windows ヘッダー ファイル:
#include <windows.h>

#include <d3d12.h>
#include <dxgi1_4.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>

#include <wrl/client.h>
#include <shlwapi.h>

// WORKAROUND: Undefined macro which defiend windows.h
#undef near
#undef far

#include "DX12/DescriptorHeap.h"
#include "DX12/Buffer.h"
#include "DX12/RootSignature.h"
#include "DX12/PipelineState.h"
#include "DX12/CommandList.h"
