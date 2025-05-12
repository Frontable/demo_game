







#pragma once

#include "Types.h"
#include "System.h"
#include <unordered_map>
#include <memory>
#include <type_traits>

#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

class ENGINE_API SystemManager {
private:
    std::unordered_map<size_t, std::shared_ptr<System>> m_systems;
    std::unordered_map<size_t, Signature> m_sysSignature;

public:
    template<typename T>
    void registerSystem(std::shared_ptr<T> system) {
        static_assert(std::is_base_of<System, T>::value, "T must be derived from System");
        size_t code = typeid(T).hash_code();
        m_systems[code] = system;
        m_sysSignature[code] = Signature();
    }

    void entitySignatureChange(Entity entity, Signature signature) {
        for (const auto& pair : m_systems) {
            const auto& code = pair.first;
            const auto& system = pair.second;
            const auto& systemSignature = m_sysSignature[code];
            if ((signature & systemSignature) == systemSignature) {
                system->m_entities.insert(entity);
            }
            else {
                system->m_entities.erase(entity);
            }
        }
    }

    template<typename T>
    Signature& getSignature() {
        return m_sysSignature[typeid(T).hash_code()];
    }

    template<typename T>
    void setSignature(Signature signature) {
        m_sysSignature[typeid(T).hash_code()] = signature;
    }

private:
    template<typename T>
    std::shared_ptr<T> getSystem() {
        return std::static_pointer_cast<T>(m_systems[typeid(T).hash_code()]);
    }
};
