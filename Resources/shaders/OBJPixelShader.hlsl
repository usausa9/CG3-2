#include "OBJShaderHeader.hlsli"

Texture2D<float4> tex : register(t0); // 0番スロットに設定されたテクスチャ
SamplerState smp : register(s0); // 0番スロットに設定されたサンプラー

float4 main(VSOutput input) : SV_TARGET
{
	// テクスチャマッピング
    float4 texcolor = tex.Sample(smp, input.uv);
	//return float4(texcolor.rgb * shade_color, texcolor.a * m_alpha);

	// シェーディングによる色で描画
    return input.color * texcolor;
}