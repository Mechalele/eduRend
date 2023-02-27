
Texture2D texDiffuse : register(t0);

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
	return WorldPos;
	return m_lightpos;
	return float4(input.Normal*0.5+0.5, 1);
	
	// Debug shading #2: map and return texture coordinates as a color (blue = 0)
//	return float4(input.TexCoord, 0, 1);
}