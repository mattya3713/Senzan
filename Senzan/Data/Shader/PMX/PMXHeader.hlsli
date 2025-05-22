struct Output
{
    float4 svpos    : SV_POSITION;  // システム用頂点座標.
    float4 pos      : POSITION;     // システム用頂点座標.
    float4 normal   : NORMAL0;      // 法線ベクトル.
    float4 vnormal  : NORMAL1;      // 法線ベクトル.
    float2 uv       : TEXCOORD;     // UV値.
    float3 ray      : VECTOR;       // ベクトル.
};

Texture2D<float4> tex   : register(t0);
Texture2D<float4> toon  : register(t1);
Texture2D<float4> sph   : register(t2);

SamplerState smp        : register(s0);
SamplerState smpToon    : register(s1);

cbuffer SceneBuffer : register(b0)
{
    matrix view;
    matrix proj;
    float3 eye;
};

cbuffer Transform : register(b1)
{
    matrix world; // ワールド変換行列
    matrix bones[256]; // ボーン行列.
}

cbuffer Material : register(b2)
{
    float4 diffuse;
    float4 specular;
    float3 ambient;
    float  padding;
};
