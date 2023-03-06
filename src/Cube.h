#pragma once
#include "model.h"
class Cube : public Model
{  
	unsigned m_number_of_indices = 0;
	std::vector<Material> m_materials;

public:

	Cube(ID3D11Device* dxdevice, ID3D11DeviceContext* dxdevice_context, ID3D11Buffer* material_buffer);

	virtual void Render() const;

	~Cube() {}
};

