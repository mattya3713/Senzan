struct Output
{
    float4 svpos    : SV_POSITION;  // �V�X�e���p���_���W.
    float4 pos      : POSITION;     // �V�X�e���p���_���W.
    float4 normal   : NORMAL0;      // �@���x�N�g��.
    float4 vnormal  : NORMAL1;      // �@���x�N�g��.
    float2 uv       : TEXCOORD;     // UV�l.
    float3 ray      : VECTOR;       // �x�N�g��.
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
    matrix world; // ���[���h�ϊ��s��
    matrix bones[256]; // �{�[���s��.
}

cbuffer Material : register(b2)
{
	float4 diffuse;
	float4 specular;
	float3 ambient;
};