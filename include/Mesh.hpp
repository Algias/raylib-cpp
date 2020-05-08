#ifndef RAYLIB_CPP_MESH_HPP_
#define RAYLIB_CPP_MESH_HPP_



#include "./raylib-cpp-utils.hpp"

#include "./BoundingBox.hpp"
#include "./Model.hpp"

namespace raylib {
#ifdef __cplusplus
	extern "C" {
#endif
#include "raylib.h"
#ifdef __cplusplus
	}
#endif
}

namespace raylibcpp {

	class Mesh : public raylib::Mesh {
	public:
		Mesh(raylib::Mesh mesh) {
			set(mesh);
		};

		Mesh(int VertexCount = 0, int TriangleCount = 0) {
			vertexCount = VertexCount;
			triangleCount = TriangleCount;
		};

		inline void set(raylib::Mesh mesh) {
			vertexCount = mesh.vertexCount;
			triangleCount = mesh.triangleCount;
			vertices = mesh.vertices;
			texcoords = mesh.texcoords;
			texcoords2 = mesh.texcoords2;
			normals = mesh.normals;
			tangents = mesh.tangents;
			colors = mesh.colors;
			indices = mesh.indices;
			animVertices = mesh.animVertices;
			animNormals = mesh.animNormals;
			boneIds = mesh.boneIds;
			boneWeights = mesh.boneWeights;
			vaoId = mesh.vaoId;
			vboId = mesh.vboId;
		}

		GETTERSETTER(int, VertexCount, vertexCount)
			GETTERSETTER(int, TriangleCount, triangleCount)

			Mesh& operator=(const raylib::Mesh& mesh) {
			set(mesh);
			return *this;
		}

		raylib::Mesh& operator=(const Mesh& mesh) {
			set(mesh);
			return *this;
		}

		~Mesh() {
			Unload();
		}

		inline Mesh& Export(const std::string& fileName) {
			ExportMesh(*this, fileName.c_str());
			return *this;
		}

		inline void Unload() {
			raylib::UnloadMesh(*this);
		}

		inline raylib::BoundingBox BoundingBox() {
			return raylib::MeshBoundingBox(*this);
		}
		operator raylib::BoundingBox() {
			return BoundingBox();
		}

		inline Mesh& Tangents() {
			raylib::MeshTangents(this);
			return *this;
		}

		inline Mesh& Binormals() {
			raylib::MeshBinormals(this);
			return *this;
		}

		inline raylib::Model LoadModelFrom() {
			return raylib::LoadModelFromMesh(*this);
		}
		operator raylib::Model() {
			return LoadModelFrom();
		}
	};
}

#endif
