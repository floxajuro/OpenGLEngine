#pragma once

#include <GL/glew.h>

#include "IComponent.h"
#include "Model.h"

namespace Engine
{
	namespace Components
	{
		class ModelRenderer : public IComponent
		{
		private:

			Engine::Graphics::Model _mModel;

		public:

			ModelRenderer(Engine::Entity::Entity* parent);
			virtual ~ModelRenderer();

			void setModel(Engine::Graphics::Model const& model);
			Engine::Graphics::Model const& GetModel() const;
		};
	}
}

