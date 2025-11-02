#pragma once

#include <cstddef>
#include <utility>

namespace comb
{
    /**
     * @brief Interface abstraite pour tous les allocateurs
     *
     * Tous les allocateurs de Comb héritent de cette interface,
     * permettant le polymorphisme et l'interchangeabilité.
     */
    class Allocator
    {
    public:
        virtual ~Allocator() = default;

        /**
         * @brief Alloue un bloc de mémoire
         * @param size Taille en bytes
         * @param alignment Alignement requis (doit être puissance de 2)
         * @return Pointeur vers la mémoire allouée, ou nullptr si échec
         */
        virtual void* Allocate(size_t size, size_t alignment) = 0;

        /**
         * @brief Libère un bloc précédemment alloué
         * @param ptr Pointeur retourné par Allocate()
         */
        virtual void Deallocate(void* ptr) = 0;

        /**
         * @brief Construit un objet dans la mémoire allouée
         * @tparam T Type de l'objet
         * @tparam Args Types des arguments du constructeur
         * @return Pointeur vers l'objet construit, ou nullptr si échec
         */
        template<typename T, typename... Args>
        T* New(Args&&... args)
        {
            void* mem = Allocate(sizeof(T), alignof(T));
            if (!mem) return nullptr;
            return new (mem) T(std::forward<Args>(args)...);
        }

        /**
         * @brief Détruit et libère un objet
         * @tparam T Type de l'objet
         * @param ptr Pointeur vers l'objet à détruire
         */
        template<typename T>
        void Delete(T* ptr)
        {
            if (!ptr) return;
            ptr->~T();
            Deallocate(ptr);
        }

        // Stats (optionnel mais recommandé)
        virtual size_t GetUsedMemory() const { return 0; }
        virtual size_t GetTotalMemory() const { return 0; }
        virtual const char* GetName() const = 0;

    protected:
        void* m_Base{nullptr};
        size_t m_Capacity{0};
    };

} // namespace comb
