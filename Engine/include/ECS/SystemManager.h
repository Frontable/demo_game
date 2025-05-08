







#pragma once
#include "EntityManager.h"
#include <set>
#include <memory>
#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

class ENGINE_API System
{
public:
	std::set<Entity> m_entities;	

}; 

class ENGINE_API MovementSystem : public System
{
public:
	
};

class ENGINE_API SystemManager
{
private:
	std::unordered_map<size_t, std::shared_ptr<System>> m_systems;
	std::unordered_map<size_t, Signature> m_sysSignature;

public:
	
	template<typename T>
	std::shared_ptr<T> registerSystem()
	{
		static_assert(std::is_base_of<System, T>::value, "T must be derived of System");
		auto code = typeid(T).hash_code();
		m_systems[code] = std::make_shared<T>();
		m_sysSignature[code] = Signature();
		return std::static_pointer_cast<T>(m_systems[code]);
		
	}


	void entitySignatureChange(Entity entity, Signature signature)
	{

		for (auto const& pair : m_systems)
		{

			auto const& code = pair.first;
			auto const& system = pair.second;
			auto const& systemSignature = m_sysSignature[code];

			if ((signature & systemSignature) == systemSignature)
			{
				system->m_entities.insert(entity);
			}
			else
			{
				system->m_entities.erase(entity);
			}

		}

	}

	template<typename T>
	Signature getSignature()
	{
		return m_sysSignature[typeid(T).hash_code()];
	}

	template<typename T>
	void setSignature(Signature signature)
	{
		m_sysSignature[typeid(T).hash_code()] = signature;
	}

private:

	template<typename T>
	std::shared_ptr<T> getSystem()
	{
		return static_pointer_cast<T>(m_systems[typeid(T).hash_code()]);
	}

};