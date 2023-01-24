#include "Cube.h"

Cube::Cube(ID3D11Device* dxdevice, ID3D11DeviceContext* dxdevice_context) : Model(dxdevice, dxdevice_context)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned> indices;

	// Populate the vertex array with 4 Vertices
	Vertex v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10,
		v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23;

	//framsidan
	v0.Position = { -0.5f, -0.5f, 0.0f };
	v0.Normal = { 0, 0, 1 };
	v0.TexCoord = { 0, 0 };
	v1.Position = { 0.5f, -0.5f, 0.0f };
	v1.Normal = { 0, 0, 1 };
	v1.TexCoord = { 0, 1 };
	v2.Position = { 0.5f, 0.5f, 0.0f };
	v2.Normal = { 0, 0, 1 };
	v2.TexCoord = { 1, 1 };
	v3.Position = { -0.5f, 0.5f, 0.0f };
	v3.Normal = { 0, 0, 1 };
	v3.TexCoord = { 1, 0 };
	
	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);

	// Triangle #1
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	// Triangle #2
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);
	
	//V�nster sida
	v4.Position ={ -0.5f, -0.5f, -1.0f }; 
	v4.Normal = { 1, 0, 0 };
	v4.TexCoord = { 0, 0 };
	v5.Position = { -0.5f, -0.5f, 0.0f };
	v5.Normal = { 1, 0, 0 };
	v5.TexCoord = { 0, 1 };
	v6.Position = { -0.5f, 0.5f, 0.0f };
	v6.Normal = { 1, 0, 0 };
	v6.TexCoord = { 1, 1 };
	v7.Position = { -0.5f, 0.5f, -1.0f };
	v7.Normal = { 1, 0, 0 };
	v7.TexCoord = { 1, 0 };
	
	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);
	vertices.push_back(v7);

	// Triangle #1
	indices.push_back(4);
	indices.push_back(5);
	indices.push_back(7);
	// Triangle #2
	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);

	//H�ger sida
	v8.Position = { 0.5f, -0.5f, 0.0f };
	v8.Normal = { 1, 0, 0 };
	v8.TexCoord = { 0, 0 };
	v9.Position = { 0.5f, -0.5f, -1.0f };
	v9.Normal = { 1, 0, 0 };
	v9.TexCoord = { 0, 1 };
	v10.Position = { 0.5f, 0.5f, -1.0f };
	v10.Normal = { 1, 0, 0 };
	v10.TexCoord = { 1, 1 };
	v11.Position = { 0.5f, 0.5f, 0.0f };
	v11.Normal = { 1, 0, 0 };
	v11.TexCoord = { 1, 0 };

	vertices.push_back(v8);
	vertices.push_back(v9);
	vertices.push_back(v10);
	vertices.push_back(v11);
	
	// Populate the index array with two triangles
	// Triangle #1
	indices.push_back(8);
	indices.push_back(9);
	indices.push_back(11);
	// Triangle #2
	indices.push_back(9);
	indices.push_back(10);
	indices.push_back(11);

	//Baksida
	v12.Position = { 0.5f, -0.5f, -1.0f };
	v12.Normal = { 0, 0, 1 };
	v12.TexCoord = { 0, 0 };
	v13.Position = { -0.5f, -0.5f, -1.0f };
	v13.Normal = { 0, 0, 1 };
	v13.TexCoord = { 0, 1 };
	v14.Position = { -0.5f, 0.5f, -1.0f };
	v14.Normal = { 0, 0, 1 };
	v14.TexCoord = { 1, 1 };
	v15.Position = { 0.5f, 0.5f, -1.0f };
	v15.Normal = { 0, 0, 1 };
	v15.TexCoord = { 1, 0 };

	vertices.push_back(v12);
	vertices.push_back(v13);
	vertices.push_back(v14);
	vertices.push_back(v15);

	// Triangle #1
	indices.push_back(12);
	indices.push_back(13);
	indices.push_back(15);
	// Triangle #2
	indices.push_back(13);
	indices.push_back(14);
	indices.push_back(15);

	

	// Vertex array descriptor
	D3D11_BUFFER_DESC vertexbufferDesc{ 0 };
	vertexbufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexbufferDesc.CPUAccessFlags = 0;
	vertexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexbufferDesc.MiscFlags = 0;
	vertexbufferDesc.ByteWidth = (UINT)(vertices.size() * sizeof(Vertex));
	// Data resource
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = &vertices[0];
	// Create vertex buffer on device using descriptor & data
	dxdevice->CreateBuffer(&vertexbufferDesc, &vertexData, &m_vertex_buffer);
	SETNAME(m_vertex_buffer, "VertexBuffer");

	//  Index array descriptor
	D3D11_BUFFER_DESC indexbufferDesc = { 0 };
	indexbufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexbufferDesc.CPUAccessFlags = 0;
	indexbufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexbufferDesc.MiscFlags = 0;
	indexbufferDesc.ByteWidth = (UINT)(indices.size() * sizeof(unsigned));
	// Data resource
	D3D11_SUBRESOURCE_DATA indexData{ 0 };
	indexData.pSysMem = &indices[0];
	// Create index buffer on device using descriptor & data
	dxdevice->CreateBuffer(&indexbufferDesc, &indexData, &m_index_buffer);
	SETNAME(m_index_buffer, "IndexBuffer");

	m_number_of_indices = (unsigned int)indices.size();
}

void Cube::Render() const
{
	// Bind our vertex buffer
	const UINT32 stride = sizeof(Vertex); //  sizeof(float) * 8;
	const UINT32 offset = 0;
	m_dxdevice_context->IASetVertexBuffers(0, 1, &m_vertex_buffer, &stride, &offset);

	// Bind our index buffer
	m_dxdevice_context->IASetIndexBuffer(m_index_buffer, DXGI_FORMAT_R32_UINT, 0);

	// Make the drawcall
	m_dxdevice_context->DrawIndexed(m_number_of_indices, 0, 0);
}
