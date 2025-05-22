#include "PMXHeader.hlsli"

Output VS(
    float4 pos : POSITION,
    float4 normal : NORMAL,
    float2 uv : TEXCOORD,
    min16uint weight : WEIGHT,
    min16uint2 boneNo : BONENO
)
{
    // ピクセルシェーダへ渡す値.
    Output output;
    // 0~100を0~1fに丸める.
    float w = weight * 0.01f;
    // ボーンを線形補間.
    matrix bone = bones[boneNo[0]] * w + bones[boneNo[1]] * (1 - w);
    // ボーン行列を乗算.
    pos = mul(bones[boneNo[0]], pos);
    pos = mul(world, pos);
    output.svpos = mul(mul(proj, view), pos); // シェーダでは列優先なので注意
    output.pos = mul(view, pos);
    normal.w = 0; // ここ重要(平行移動成分を無効にする)
    output.normal = mul(world, normal); // 法線にもワールド変換を行う
    output.vnormal = mul(view, output.normal);
    output.uv = uv;
    output.ray = normalize(pos.xyz - mul((float4x3) view, eye).xyz); //視線ベクトル
    
    return output;
}