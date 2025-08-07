//---------------------------------------------------------------------------
// Teste Isolado - Projeto Console Application
// Completamente independente do projeto principal
//---------------------------------------------------------------------------
#include <iostream>

int main()
{
    try
    {
        std::cout << "========================================" << std::endl;
        std::cout << "    TESTE ISOLADO - TASKAPP" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << std::endl;
        
        std::cout << "Teste isolado executado com sucesso!" << std::endl;
        std::cout << "Sem dependências do projeto principal." << std::endl;
        std::cout << "Sem bibliotecas externas." << std::endl;
        std::cout << "Apenas C++ padrão." << std::endl;
        
        std::cout << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "    RESULTADO DO TESTE" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Teste concluído sem erros!" << std::endl;
        std::cout << std::endl;
        
        std::cout << "Pressione qualquer tecla para continuar..." << std::endl;
        std::cin.get();
        
        return 0;
    }
    catch (...)
    {
        std::cerr << "Erro durante execução do teste isolado!" << std::endl;
        std::cin.get();
        return 1;
    }
}
//--------------------------------------------------------------------------- 