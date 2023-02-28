
Texture2D texDiffuse : register(t0);
SamplerState texSampler : register(s0);

struct PSIn
{
	float4 Pos  : SV_Position;
	float3 WorldPos : POSITION;
	float3 Normal : NORMAL;
	float2 TexCoord : TEX;
};


//-----------------------------------------------------------------------------------------
// Pixel Shader
//-----------------------------------------------------------------------------------------

cbuffer LightCameraBuffer : register(b0)
{
	float4 m_lightpos;
	float4 m_camerapos;
}

cbuffer MaterialBuffer : register(b1)
{
	float4 AmbientColour;
	float4 DiffuseColour;
	float4 SpecularColour;
	float Shininess;
}

float4 PS_main(PSIn input) : SV_Target
{
	// Debug shading #1: map and return normal as a color, i.e. from [-1,1]->[0,1] per component
	// The 4:th component is opacity and should be = 1
	/*return float4(input.Normal*0.5+0.5, 1);*/

	// Debug shading #2: map and return texture coordinates as a color (blue = 0)
	//	return float4(input.TexCoord, 0, 1);
	
	return float4(input.WorldPos, 0);
	return m_lightpos;

	float3 N = input.Normal;
	float3 L = normalize(m_lightpos.xyz - input.WorldPos);

	float diffValue = max(dot(L, N), 0);

	float3 R = normalize(reflect(-L, N)); //reflect?? R = ??
	float3 V = normalize(m_camerapos.xyz - input.WorldPos);

	float specValue = pow(max(dot(R, V), 0), Shininess);

	float4 texColor = texDiffuse.Sample(texSampler, input.TexCoord * 100); //hur funkar denna??
	return (AmbientColour * texColor) + (texColor * DiffuseColour * diffValue) + (SpecularColour * specValue);
	
	
}