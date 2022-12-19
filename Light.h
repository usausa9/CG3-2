#pragma once
#include <DirectXMath.h>
#include <d3d12.h>
#include <d3dx12.h>
#include <assert.h>
#include <wrl.h>

class Light
{
private:
	// Microsoft::WRL::���ȗ�
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public://�T�u�N���X

	//�萔�o�b�t�@�p�f�[�^�\����
	struct ConstBufferData
	{
		XMVECTOR lightv;		//���C�g�ւ̕�����\���x�N�g��
		XMFLOAT3 lightcolor;	//���C�g�̐F
	};

private:// �ÓI�����o�ϐ�

	// �f�o�C�X
	static ID3D12Device* device;

	// �萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;
	
	XMVECTOR lightdir = { 1,0,0,0 }; // ���C�g��������
	XMFLOAT3 lightcolor = { 1,1,1 }; // ���C�g�F

	// �_�[�e�B�t���O
	bool dirty = false;

public: // �ÓI�����o�֐�

	// �ÓI������
	static void StaticInitalize(ID3D12Device* device);

	static Light* Creare();

public: // �����o�֐�

	// ������
	void Initalize();

	// �X�V
	void Update();

	// �`��
	void Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex);

	// �萔�o�b�t�@�]��
	void TransferConstBuffer();

	// ���C�g�̕������Z�b�g
	void SetLightDir(const XMVECTOR& lightdir);

	// ���C�g�̐F���Z�b�g
	void SetLightColor(const XMFLOAT3& lightcolor);
};