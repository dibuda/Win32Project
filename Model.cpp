#include "model.h"
#include "utils.h"

Model::Model()
{

}

Model::~Model()
{

}

void Model::Init(const char *modelPath)
{
	struct FloatData
	{
		float v[3];
	};

	struct VertexDefine
	{
		int PosIndex;
		int texcoordIndex;
		int normaleIndex;

	};

	int nFileSize = 0;
	unsigned char *fileContent = LoadFileContent(modelPath, nFileSize);
	if (fileContent ==nullptr)
	{
		return;
	}
	std::stringstream ssFileContent((char*)fileContent);
	char szOneLine[256];
	std::vector<FloatData> positions, texcoords, normales;
	std::vector<VertexDefine> vertexes;
	std::vector<int>indexes;
	while (!ssFileContent.eof())
	{
		memset(szOneLine, 0, 256);
		ssFileContent.getline(szOneLine, 256);
		std::string temp;
		if (strlen(szOneLine)>0)
		{
			if (szOneLine[0]=='v')
			{
				std::stringstream ssOneLine(szOneLine);

				if (szOneLine[1] == 'f')
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					texcoords.push_back(floatData);
					printf("texcoord:%f,%f\n", floatData.v[0], floatData.v[1]);
				}
				else if (szOneLine[1] == 'n')
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					ssOneLine >> floatData.v[2];
					normales.push_back(floatData);
					printf("normale:%f,%f,%f\n", floatData.v[0], floatData.v[1], floatData.v[2]);
				}
				else
				{
					ssOneLine >> temp;
					FloatData floatData;
					ssOneLine >> floatData.v[0];
					ssOneLine >> floatData.v[1];
					ssOneLine >> floatData.v[2];
					positions.push_back(floatData);
					printf("position:%f,%f,%f\n", floatData.v[0], floatData.v[1], floatData.v[2]);

				}
			}
			else if (szOneLine[0] == 'f')
			{
				std::stringstream ssOneLine(szOneLine);
				ssOneLine >> temp;
				std::string vertexStr;
				for (int i=0;i<3;i++)
				{
					ssOneLine >> vertexStr;
					size_t pos = vertexStr.find_first_of('/');
					std::string posIndexStr = vertexStr.substr(0, pos);
					size_t pos2 = vertexStr.find_first_of('/', pos + 1);
					std::string texcoordIndexStr = vertexStr.substr(pos + 1, pos2 - 1 - pos);
					std::string normalIndexStr = vertexStr.substr(pos + 1, vertexStr.length() - 1 - pos);

					VertexDefine vd;
					vd.PosIndex = atoi(posIndexStr.c_str());
					vd.texcoordIndex = atoi(texcoordIndexStr.c_str());
					vd.normaleIndex = atoi(normalIndexStr.c_str());

					int nCurrentVertexIndex = -1;
					int nCurrentVertexCount = (int)vertexes.size();
					for (int j=0;j<nCurrentVertexCount;j++)
					{
						if (vertexes[j].PosIndex==vd.PosIndex&&vertexes[j].texcoordIndex == vd.texcoordIndex&&vertexes[j].normaleIndex == vd.normaleIndex)
						{
							nCurrentVertexCount = j;
							break;
						}
					}
					if (nCurrentVertexIndex==-1)
					{
						nCurrentVertexIndex= (int)vertexes.size();
						vertexes.push_back(vd);
					}
					indexes.push_back(nCurrentVertexIndex);

				}
			}
		}


	}
	mIndexCount= (int)vertexes.size();
	mIndexes = new unsigned short[mIndexCount];
	for (int i=0;i<mIndexCount;i++)
	{
		mIndexes[i] = indexes[i];
	}
	int vertexCount= (int)vertexes.size();

	mVertexes = new VertexData[vertexCount];

	for (int i = 0;i < vertexCount;i++)
	{
		memcpy(mVertexes[i].position, positions[vertexes[i].PosIndex - 1].v, sizeof(float) * 3);
		memcpy(mVertexes[i].texcoord, texcoords[vertexes[i].texcoordIndex - 1].v, sizeof(float) * 2);
		memcpy(mVertexes[i].normal, normales[vertexes[i].normaleIndex - 1].v, sizeof(float) * 3);
	}

	delete fileContent;
}

void Model::Draw()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glBegin(GL_TRIANGLES);
	for (int i=0;i<mIndexCount;i++)
	{
		glTexCoord2fv(mVertexes[i].texcoord);
		glNormal3fv(mVertexes[i].normal);
		glVertex3fv(mVertexes[i].position);
	}
	glEnd();
	glPopMatrix();
}

