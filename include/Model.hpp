#ifndef RAYLIB_CPP_MODEL_HPP_
#define RAYLIB_CPP_MODEL_HPP_



#include "./raylib-cpp-utils.hpp"
#include "./Mesh.hpp"

namespace raylib {
#ifdef __cplusplus
	extern "C" {
#endif
#include "raylib.h"
#ifdef __cplusplus
	}
#endif
}

#include <RayHitInfo.hpp>
namespace raylibcpp {

	class Model : public raylib::Model {
	public:
		Model(raylib::Model model) {
			set(model);
		};

		Model(const std::string& fileName) {
			set(raylib::LoadModel(fileName.c_str()));
		};

		Model(raylib::Mesh mesh) {
			set(LoadModelFromMesh(mesh));
		};

		~Model() {
			Unload();
		}

		inline void set(raylib::Model model) {
			transform = model.transform;

			meshCount = model.meshCount;
			meshes = model.meshes;

			materialCount = model.materialCount;
			materials = model.materials;
			meshMaterial = model.meshMaterial;
			boneCount = model.boneCount;
			bones = model.bones;
			bindPose = model.bindPose;
		}

		GETTERSETTER(raylib::Matrix, Transform, transform)
			GETTERSETTER(int, MeshCount, meshCount)
			GETTERSETTER(int, MaterialCount, materialCount)

			Model& operator=(const raylib::Model& model) {
			set(model);
			return *this;
		}

		raylib::Model& operator=(const Model& model) {
			set(model);
			return *this;
		}

		inline void Unload() {
			raylib::UnloadModel(*this);
		}

		inline Model& SetMeshMaterial(int meshId, int materialId) {
			raylib::SetModelMeshMaterial(this, meshId, materialId);
			return *this;
		}

		inline RayHitInfo GetCollision(raylib::Ray ray) {
			return raylib::GetCollisionRayModel(ray, *this);
		}

		inline Model& UpdateModelAnimation(raylib::ModelAnimation anim, int frame) {
			raylib::UpdateModelAnimation(*this, anim, frame);
			return *this;
		}

		inline bool IsModelAnimationValid(raylib::ModelAnimation anim) {
			return raylib::IsModelAnimationValid(*this, anim);
		}
	};
}

#endif
