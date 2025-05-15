#include "PMXShaderHeader.hlsli"

Output VS(
    float4 pos : POSITION,
    float4 normal : NORMAL,
    float2 uv : TEXCOORD,
    min16uint Weight : WEIGHT,
    min16uint2 BoneNo : BONENO)
{
    Output output;
    pos = mul(world, pos);
    output.svpos = mul(mul(proj, view), pos);
    output.uv = uv;
    output.normal = float4(normal.xyz, 1);
    return output;
    //Output output;

    // スキニング計算
    //float weightF = Weight / 255.0f;

    //float4 skinnedPos =
    //    mul(Bones[BoneNo.x], pos) * (1.0f - weightF) +
    //    mul(Bones[BoneNo.y], pos) * weightF;

    //float4 skinnedNormal =
    //    mul(Bones[BoneNo.x], normal) * (1.0f - weightF) +
    //    mul(Bones[BoneNo.y], normal) * weightF;

    // ワールド変換とビュー・プロジェクション変換
    //skinnedPos = mul(World, skinnedPos);
    //output.svpos = mul(proj, mul(view, skinnedPos));

    //output.uv = uv;
    //output.normal = skinnedNormal;

    //return output;
}
