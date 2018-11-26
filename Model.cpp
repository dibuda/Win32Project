#include "model.h"
#include "utils.h"
#include <string>
#include <sstream>
#include <vector>

Model::Model()
{
	memset(mAmbientMaterial, 0, sizeof(mAmbientMaterial));
	memset(mDiffuseMaterial, 0, sizeof(mDiffuseMaterial));
	memset(mSpecularMaterial, 0, sizeof(mSpecularMaterial));

}
void Model::Init(const char*modelPath)
{
	struct FloatData
	{
		float v[3];
	};

	struct VerticeDefine
	{
		int posIndex;
		int texcoordIndex;
		int normalIndex;
	};
	std::vector<FloatData> positions, texcoords, normals;
	std::vector<VerticeDefine> vertexes;//unique vertex
	std::vector<int> indexes;//

	int nFileSize = 0;
	unsigned char*fileContent = LoadFileContent(modelPath, nFileSize);
	std::stringstream ssFileContent((char*)fileContent);
	std::string temp;
	char szOneLine[256];
	while (!ssFileContent.eof())
	{
		memset(szOneLine, 0, 256);
		ssFileContent.getline(szOneLine, 256);
		if (strlen(szOneLine)>0)
		{
			if (szOneLine[0] == 'v')
			{
				std::stringstream ssOneLine(szOneLine);
				if (szOneLine[1] == 't')
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					texcoords.push_back(floatData);
				}
				else if (szOneLine[1] == 'n')
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					ssOneLine >> floatData.v[2];
					normals.push_back(floatData);
				}
				else
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					ssOneLine >> floatData.v[2];
					positions.push_back(floatData);
				}
			}
			else if (szOneLine[0] == 'f')
			{
				std::stringstream ssOneLine(szOneLine);
				ssOneLine >> temp;//
				std::string vertexStr;// 1/1/1
				for (int i = 0; i<3; i++)
				{
					ssOneLine >> vertexStr;
					size_t pos = vertexStr.find_first_of('/');
					std::string posIndexStr = vertexStr.substr(0, pos);
					size_t pos2 = vertexStr.find_first_of('/', pos + 1);
					std::string texcoordIndexStr = vertexStr.substr(pos + 1, pos2 - 1 - pos);
					std::string normalIndexStr = vertexStr.substr(pos2 + 1, vertexStr.length() - 1 - pos2);
					VerticeDefine vd;
					vd.posIndex = atoi(posIndexStr.c_str());
					vd.texcoordIndex = atoi(texcoordIndexStr.c_str());
					vd.normalIndex = atoi(normalIndexStr.c_str());
					int nCurrentVertexIndex = -1;
					int nCurrentVertexCount = (int)vertexes.size();
					for (int j = 0; j<nCurrentVertexCount; ++j)
					{
						if (vertexes[j].posIndex == vd.posIndex&&
							vertexes[j].normalIndex == vd.normalIndex&&
							vertexes[j].texcoordIndex == vd.texcoordIndex)
						{
							nCurrentVertexIndex = j;
							break;
						}
					}
					if (nCurrentVertexIndex == -1)
					{
						nCurrentVertexIndex = (int)vertexes.size();
						vertexes.push_back(vd);
					}
					indexes.push_back(nCurrentVertexIndex);
				}
			}
		}
	}
	printf("unique vertex count %u index count %u\n", vertexes.size(), indexes.size());
	mIndexCount = (int)indexes.size();
	mIndexes = new unsigned short[mIndexCount];
	for (int i = 0; i<mIndexCount; ++i)
	{
		mIndexes[i] = indexes[i];
	}
	int vertexCount = (int)vertexes.size();
	mVertexes = new VertexData[vertexCount];
	for (int i = 0; i<vertexCount; ++i)
	{
		memcpy(mVertexes[i].position, positions[vertexes[i].posIndex - 1].v, sizeof(float) * 3);
		memcpy(mVertexes[i].texcoord, texcoords[vertexes[i].texcoordIndex - 1].v, sizeof(float) * 2);
		memcpy(mVertexes[i].normal, normals[vertexes[i].normalIndex - 1].v, sizeof(float) * 3);
	}
	delete fileContent;
}

void Model::Draw()
{
	static float angle = 0.0f;
	angle += 0.2f;
	if (angle >= 360.0f)
	{
		angle = 0.0f;
	}

	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mAmbientMaterial);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mDiffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mSpecularMaterial);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i<mIndexCount; ++i)
	{
		glTexCoord2fv(mVertexes[mIndexes[i]].texcoord);
		glNormal3fv(mVertexes[mIndexes[i]].normal);
		glVertex3fv(mVertexes[mIndexes[i]].position);
	}
	glEnd();
	glPopMatrix();
}

void Model::SetAmbienMaterial(float r, float g, float b, float a)
{
	mAmbientMaterial[0] = r;
	mAmbientMaterial[1] = g;
	mAmbientMaterial[2] = b;
	mAmbientMaterial[3] = a;
}
void Model::SetDiffuseMaterial(float r, float g, float b, float a)
{
	mDiffuseMaterial[0] = r;
	mDiffuseMaterial[1] = g;
	mDiffuseMaterial[2] = b;
	mDiffuseMaterial[3] = a;
}
void Model::SetSpecularMaterial(float r, float g, float b, float a)
{
	mSpecularMaterial[0] = r;
	mSpecularMaterial[1] = g;
	mSpecularMaterial[2] = b;
	mSpecularMaterial[3] = a;
}