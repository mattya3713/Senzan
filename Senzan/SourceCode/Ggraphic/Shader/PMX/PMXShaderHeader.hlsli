struct Output
{
	float4 svpos : SV_POSITION;
	float4 normal: NORMAL;
	float2 uv	 : TEXCOORD;
};

Texture2D<float4> tex : register(t0);
Texture2D<float4> toon : register(t1);
Texture2D<float4> sph : register(t2);
SamplerState smp : register(s0);
SamplerState smpToon : register(s1);

cbuffer SceneBuffer : register(b0)
{
	matrix view;
	matrix proj;
	float3 eye;
};

cbuffer Transform : register(b1)
{
	matrix world;
};

cbuffer Material : register(b2)
{
	float4 diffuse;
	float4 specular;
	float3 ambient;
};