#include <iostream>
#include <string>
#include <vector>
#include "lib.hpp"
int testevu(void);
int testebre(void);

int testevu() {
    //-------------------------------------------------teste de endereço-----------------------------------------------------------//
    //teste contrutor padrão (deve ter setado para padrão)
    final::endereco endereco01;
    //teste de set
    endereco01.set_rua("rua generica");
    endereco01.set_pais("brasil");
    endereco01.set_estado("são paulo");
    endereco01.set_cidade("são paulo");
    endereco01.set_cep("13579000");
    //teste de set inválido
    endereco01.set_cep("999");
    endereco01.set_cep("1357900h");
    //teste de get
    std::string hldstring= endereco01.get_cep();
    hldstring=endereco01.get_rua();
    hldstring=endereco01.get_pais();
    hldstring=endereco01.get_estado();
    hldstring=endereco01.get_cidade();
    //teste de construtor secundário
    final::endereco endereco02("avenida washingtonn luiz 300", "sao paulo", "sao paulo", "brasil", "09009008");
    //teste de sobrecarga de <<
    std::cout<<endereco02;
    std::cout<<std::endl;
    
    
    //--------------------------------------------------teste de data-------------------------------------------------------------//
    //teste de construtor padrão
    final::data data01;
    data01.set_dia(31);
    data01.set_mes(1);
    data01.set_ano(2000);
    //teste set inválido
    data01.set_dia(33);
    //teste ano bissexto
    data01.set_mes(2);
    data01.set_ano(2020);
    data01.set_dia(29);
    //teste construtor com argumentos;
    final::data data02(29, 2, 2020);
    //teste sobrecarga <<
    std::cout<<data02;
    std::cout<<std::endl;
    
    //--------------------------------------------------teste de pessoa------------------------------------------------------------//
    //teste de consrtutor padrão
    final::pessoa pessoa01;
    //teste de set
    pessoa01.set_nome("Lery");
    pessoa01.set_genero(final::genero::MASCULINO);
    pessoa01.set_cpf("09809809809");
    //teste de set inválido
    pessoa01.set_cpf("789");
    pessoa01.set_cpf("0980980980k");
    //teste de get
    hldstring=pessoa01.get_cpf();
    hldstring=pessoa01.get_nome();
    final::genero hldgenero= pessoa01.get_genero();
    //teste de construtor com argumento
    final::pessoa pessoa02("Lery", final::genero::MASCULINO, "09809809809");
    //teste de sobrecarga de <<
    std::cout<<pessoa02;
    std::cout<<std::endl;
    
    //--------------------------------------------------teste de motorista---------------------------------------------------------//
    //teste construtor padrão
    final::motorista motorista01;
    //teste set
    motorista01.set_anos_exp(5);
    motorista01.set_cpf("09809809809");
    motorista01.set_nome("bob");
    motorista01.set_genero(final::genero::MASCULINO);
    motorista01.set_status(false);
    motorista01.set_num_carteira("09809809809");
    motorista01.set_vencimento_carteira({8,03,2020});
    //teste get
    unsigned hldunsigned=motorista01.get_anos_exp();
    hldstring=motorista01.get_cpf();
    hldstring=motorista01.get_nome();
    hldgenero=motorista01.get_genero();
    bool hldbool = motorista01.get_status();
    hldstring=motorista01.get_num_carteira();
    final::data hlddate= motorista01.get_vencimento_carteira();
    //teste set inválido
    motorista01.set_num_carteira("099");
    motorista01.set_num_carteira("0980980980k");
    motorista01.set_cpf("999999");
    motorista01.set_cpf("0980980988u");
    //teste construtor secundário
    final::motorista motorista02(5, "09809809809", {3,3,2020}, false, "lery", final::genero::FEMININO, "12312312312");
    //teste sobrecarga <<
    std::cout<<motorista02;
    std::cout<<std::endl;
    
    //--------------------------------------------------teste de veiculo----------------------------------------------------------//
    //construtor padrão
    final::veiculo veiculo01;
    //teste set
    veiculo01.set_placa("bee4r22");
    veiculo01.set_renavam("481014772");
    veiculo01.set_ultima_revisao({12,1,2121});
    //teste get
    hldstring=veiculo01.get_placa();
    hldstring=veiculo01.get_renavam();
    hlddate=veiculo01.get_ultima_revisao();
    //teste set inválido
    veiculo01.set_renavam("23");
    veiculo01.set_placa("01");
    //teste construtor secundário
    final::veiculo veiculo02("bee4r22", "481014772", {12,1,2121});
    //teste sobrecarga
    std::cout<<veiculo02;
    std::cout<<std::endl;
    
    //--------------------------------------------------teste de caminhao----------------------------------------------------------//
    //construtor padrão
    final::caminhao caminhao01;
    //teste set
    caminhao01.set_modelo("volvo");
    caminhao01.set_id(22);
    caminhao01.set_placa("bee4r22");
    caminhao01.set_renavam("481014772");
    caminhao01.set_ultima_revisao({12,1,2121});
    caminhao01.set_status(false);
    //teste get
    hldstring=caminhao01.get_modelo();
    hldunsigned=caminhao01.get_id();
    hldstring=caminhao01.get_placa();
    hldstring=caminhao01.get_renavam();
    hlddate=caminhao01.get_ultima_revisao();
    //teste set inválido
    caminhao01.set_renavam("23");
    caminhao01.set_placa("01");
    //teste construtor secundário
    final::caminhao caminhao02("volvo",22, false, "bee4r22", "481014772", {12,1,2121});
    //teste sobrecarga
    std::cout<<caminhao02;
    std::cout<<std::endl;
    
    //--------------------------------------------------teste de ordem-------------------------------------------------------------//
    //construtor padrão
    final::ordem ordem01;
    //teste de set
    ordem01.set_observacoes("material hospitalar");
    ordem01.set_caminhao_usado(caminhao01);
    ordem01.set_data_chegada({2,2,2020});
    ordem01.set_data_saida({1,1,2020});
    ordem01.set_motorista_usado(motorista01);
    //teste de get
    hldstring=ordem01.get_observacoes();
    final::caminhao hldcaminhao=ordem01.get_caminhao_usado();
    hlddate=ordem01.get_data_chegada();
    hlddate=ordem01.get_data_saida();
    final::motorista hldmotorista=ordem01.get_motorista_usado();
    //teste de colocar inválidos
    caminhao02.set_status(true);
    motorista02.set_status(true);
    hldbool=ordem01.set_motorista_usado(motorista02);
    hldbool=ordem01.set_caminhao_usado(caminhao02);
    //teste de contrutor secundário
    caminhao01.set_status(false);
    motorista01.set_status(false);
    final::ordem ordem02({1,1,2020}, {2,2,2020}, motorista01, caminhao01, "material hospitalar");
    //teste sobrecarga
    std::cout<<ordem02;
    
    return 0;
}

int testebre(){
    std::cout<<"\n\n\n Teste\n\n\n";
    
    
    final::Lista_geral lista1;
    
    
    lista1.fazer_pedido();
    
    
    lista1.insere_ordem({1,1,2020}, {2,2,2020}, "material hospitalar");
    lista1.insere_ordem({1,1,2020}, {2,2,2020}, "fruta");
    lista1.insere_ordem({1,1,2020}, {2,2,2020}, "carros");
    lista1.insere_ordem({1,1,2020}, {2,2,2020}, "tvs");
    
    
    lista1.fazer_pedido();
    
    lista1.insere_caminhao("volvo",22, true, "bee2e12", "481014772", {12,1,2121});
    lista1.insere_caminhao("scania",22, true, "bee9r22", "481014772", {12,1,2121});
    lista1.insere_caminhao("mercedes",22, false, "bee8r44", "481014772", {12,1,2121});
    lista1.insere_caminhao("iveco",22, false, "bee4r22", "481014772", {12,1,2121});
    
    lista1.insere_motorista(5, "09809809809", {3,3,2020}, false, "Sara", final::genero::FEMININO, "12312312312");
    lista1.insere_motorista(5, "09809809809", {3,3,2020}, true, "Breno", final::genero::MASCULINO, "12312312312");
    lista1.insere_motorista(5, "09809809809", {3,3,2020}, false, "Pedro", final::genero::MASCULINO, "12312312312");
    lista1.insere_motorista(5, "09809809809", {3,3,2020}, true, "lorena", final::genero::FEMININO, "12312312312");
    lista1.insere_motorista(5, "09809809809", {3,3,2020}, false, "Paulo", final::genero::MASCULINO, "12312312312");
    
    
    std::cout<<"Quantidade de caminhões registrados :"<<lista1.tamanho_banco_de_dados_caminhao()    <<std::endl;
    std::cout<<"Quantidade de motoristas registrados:"<<lista1.tamanho_banco_de_dados_motorista()   <<std::endl;
    std::cout<<"Quantidade de ordens registrados    :"<<lista1.tamanho_banco_de_dados_ordem()       <<std::endl;
    
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    
    std::cout<<"\n\nTeste de impressão\n\n";
    
    
    lista1.imprimir_banco_de_dados_caminhao();
    
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    lista1.imprimir_banco_de_dados_motorista();
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    lista1.imprimir_banco_de_dados_ordem();
    
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    lista1.fazer_pedido();
    
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    
    std::cout<<"\n\nTeste de remoção\n\n";
    
    
    lista1.imprimir_banco_de_dados_caminhao();
    
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    lista1.imprimir_banco_de_dados_motorista();
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    lista1.imprimir_banco_de_dados_ordem();
    //lista1.remover_motorista("");
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    lista1.imprimir_banco_de_dados_motorista();
    
    std::cout<<"\n\n###########################################################\n\n"<<std::endl;
    
    //lista1.remover_motorista("Breno");
    //lista1.remover_motorista("lorena");
    
    //lista1.mudar_situacao_caminhao("bee4r22");
    //lista1.mudar_situacao_caminhao("bee2e12");
    lista1.mudar_situacao_motorista("lorena");
    lista1.mudar_situacao_motorista("julio");
    std::cout<<"\nQuantidade de caminhões  registrados:"<<lista1.tamanho_banco_de_dados_caminhao()<<std::endl;
    std::cout<<"\nQuantidade de motoristas registrados:"<<lista1.tamanho_banco_de_dados_motorista()<<std::endl;
    std::cout<<"\nQuantidade de ordens     registradas:"<<lista1.tamanho_banco_de_dados_ordem()<<std::endl;
    
    lista1.imprimir_banco_de_dados_caminhao();
    lista1.imprimir_banco_de_dados_motorista();
    
    
    return 0;
}

//int main (){

//    //testevu();
//    //testebre();
//
//    final::Lista_geral lista1;
//    int opt;
//    std::cout<< "1 para inserir caminhão, 2 para imprimir caminhões,  -1 para sair \n";
//    std::cout<< "digite opção:\n";
//    std::cin>>opt;
//    while (opt!=-1) {
//    switch (opt) {
//        case 1:
//        { std::string mod;                      //precias ter parênteses para desinicializar variável mod quando terminar esse case
//            std::cout<<"digite modelo: ";
//            std::cin>>mod;
//            unsigned ida;
//            std::cout<<"digite id do caminhao: ";
//            std::cin>>ida;
//            bool situacao;
//            std::cout<<"digite situação (0 livre 1 ocupado): ";
//            std::cin>>situacao;
//            std::string placa;
//            std::cout<<"digite placa: ";
//            std::cin>>placa;
//            std::string renavam;
//            std::cout<<"digite renavam: ";
//            std::cin>>renavam;
//            unsigned dia, mes, ano;
//            std::cout<<"digite dia mes e ano da data de revisão: ";
//            std::cin>>dia>>mes>>ano;
//            lista1.insere_caminhao(mod, ida, situacao, placa, renavam, {dia, mes, ano});    //como lista foi inicializada fora do colchete foi inserido dentro dos colchetes mas ela continua a existir mesmo
//        }
//            break;
//        case 2:
//            lista1.imprimir_banco_de_dados_caminhao();
//            break;
//
//        default:
//            std::cout<<"numero inválio de operação";
//            break;
//    }
//        std::cout<< "digite opção:\n";
//        std::cin>>opt;
//    }


int main(){
    final::Lista_geral lista1;
    int opcao=0;
    std::string nome_empresa="Sem nome";
    
    std::cout<<"\n\n\n\n                                              Bem vindo a "<<nome_empresa<<"\n\n\n\n";
    std::cout<<"                                            Digita 1 para cadastrar motorista.\n";
    std::cout<<"                                            Digita 2 para cadastrar caminhão.\n";
    std::cout<<"                                            Digita 3 para remover motorista.\n";
    std::cout<<"                                            Digita 4 para remover caminhão.\n";
    std::cout<<"                                            Digita 5 para visualizar banco de dados.\n";
    std::cout<<"                                            Digita 6 para abrir ordem de serviço.\n";
    std::cout<<"                                            Digita 7 para cadastrar serviço.\n";
    std::cout<<"                                            Digita 8 para visualizar lista de serviços.\n";
    std::cout<<"                                            Digita 9 para remover serviço.\n";
    std::cout<<"                                            Digita 10 para configuração.\n";
    
    std::cout<<"\n\n                                            Digita 11 para sair treminar programa.\n";
    std::cout<<"\n\n\n\n";
    
    while (opcao!=11){
        std::cout<<"\nDigite aqui a opção da nova operação: ";
        std::cin>>opcao;
        switch (opcao) {
            case 1:
            {
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"                                   CADASTRO DE MOTORISTA";std::cout<<std::endl<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"FAVOR INSERIR OS DADOS ABAIXO:";std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;
                
                std::cout<<"Em genero digite 1 para MASCULINO e 2 para se FEMININO.";std::cout<<std::endl;
                std::cout<<"Em situacão digite 1 para Em TRABALHO e 2 para SEM TRABALHO.";std::cout<<std::endl;std::cout<<std::endl;
                bool situacao;
                unsigned dia;
                unsigned mes;
                unsigned ano;
                std::string nome;
                std::string cpf;
                std::string num_carteira;
                int aux_situacao;
                int aux_genero;
                unsigned anos_exp;
                
                std::cout<<"Nome:";std::cin>>nome;
                std::cout<<"CPF: ";std::cin>>cpf;
                std::cout<<"Genero: ";std::cin>>aux_genero;
                std::cout<<"Numero da carteira de motorista:";std::cin>>num_carteira;
                std::cout<<"Situação que se encontra: ";std::cin>>aux_situacao;
                std::cout<<"Anos de experiência: ";std::cin>>anos_exp;
                std::cout<<"Data de vencimento da carteira de motorista:";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"Dia: ";std::cin>>dia;
                std::cout<<"Mes: ";std::cin>>mes;
                std::cout<<"Ano: ";std::cin>>ano;
                if(aux_situacao==1){
                    
                    situacao=true;
                }
                else{
                    
                    situacao=false;
                }
                
                if(aux_genero==1){
                    
                    lista1.insere_motorista(anos_exp,num_carteira,{dia,mes,ano},situacao,nome,final::genero::MASCULINO,cpf);
                    
                }
                else{
                    
                    lista1.insere_motorista(anos_exp,num_carteira,{dia,mes,ano},situacao,nome,final::genero::FEMININO,cpf);
                }
                
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"Cadastro feito com sucesso.";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
            }
                break;
                
            case 2:
            {
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"                                   CADASTRO DE CAMINHÃO";std::cout<<std::endl<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"FAVOR INSERIR OS DADOS ABAIXO:";std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;
                
                
                std::cout<<"Em situacão digite 1 para Em TRABALHO e 2 para SEM TRABALHO.";std::cout<<std::endl;std::cout<<std::endl;
                bool situacao;
                unsigned dia;
                unsigned mes;
                unsigned ano;
                int aux_situacao;
                unsigned id;
                std::string modelo_cam;
                std::string placa;
                std::string renavam;
                
                std::cout<<"Modelo: ";std::cin>>modelo_cam;std::cout<<std::endl;
                std::cout<<"Idade: ";std::cin>>id;std::cout<<std::endl;
                std::cout<<"Placa: ";std::cin>>placa;std::cout<<std::endl;
                std::cout<<"Renavam:";std::cin>>renavam;std::cout<<std::endl;
                std::cout<<"\nSituação que se encontra: ";std::cin>>aux_situacao;
                std::cout<<"Data ultima revisão: ";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"Dia: ";std::cin>>dia;
                std::cout<<"Mes: ";std::cin>>mes;
                std::cout<<"Ano: ";std::cin>>ano;
                
                if(aux_situacao==1){
                    
                    situacao=true;
                }
                else{
                    
                    situacao=false;
                }
                
                lista1.insere_caminhao(modelo_cam,id,situacao,placa,renavam,{dia,mes,ano});
                
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"Cadastro feito com sucesso.";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
                
            }
                break;
            case 7:
            {
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"                                   CADASTRO DE SERVIÇO";std::cout<<std::endl<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"FAVOR INSERIR OS DADOS ABAIXO:";std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;
                std::string observacoes;
                unsigned dia;
                unsigned mes;
                unsigned ano;
                unsigned diaa;
                unsigned mess;
                unsigned anoo;
                
                std::cout<<"Observacoes: ";std::cin>>observacoes;
                std::cout<<"Data de saida: ";std::cout<<std::endl;std::cout<<std::endl;
                
                std::cout<<"Dia: ";std::cin>>dia;
                std::cout<<"Mes: ";std::cin>>mes;
                std::cout<<"Ano: ";std::cin>>ano;
                
                std::cout<<"Data de chegada: ";std::cout<<std::endl;std::cout<<std::endl;
                
                std::cout<<"Dia: ";std::cin>>diaa;
                std::cout<<"Mes: ";std::cin>>mess;
                std::cout<<"Ano: ";std::cin>>anoo;
                
                
                lista1.insere_ordem({dia,mes,ano},{diaa,mess,anoo}, observacoes);
                
                
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"Cadastro feito com sucesso.";std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
            }
                break;
            case 5:
            {   std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
               std::cout<<"                                   Banco de dados da empresa "<<nome_empresa;std::cout<<std::endl<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                
                std::cout<<"Numero de caminhões registrados: "<<lista1.tamanho_banco_de_dados_caminhao();std::cout<<std::endl;
                std::cout<<"Numero de motorista registrados: "<<lista1.tamanho_banco_de_dados_motorista();std::cout<<std::endl;
                std::cout<<"Numero de serviço registrados: "<<lista1.tamanho_banco_de_dados_ordem()<<std::endl<<std::endl;
                
                std::cout<<"Numero de caminhões em serviço: "<<lista1.tamanho_caminhao_n_disponivel()<<std::endl;
                std::cout<<"Numero de motorista em serviço: "<<lista1.tamanho_motorista_n_disponivel()<<std::endl<<std::endl;
                std::cout<<"Numero de caminhões sem serviço: "<<lista1.tamanho_caminhao_disponivel()<<std::endl;
                std::cout<<"Numero de motorista sem serviço: "<<lista1.tamanho_motorista_disponivel()<<std::endl;
                
                std::cout<<"\n\nLista de caminhões registrados\n\n\n";
                
                if(lista1.tamanho_banco_de_dados_caminhao()==0){
                    
                    std::cout<<"A lista está vazia";
                    
                }
                else{
                    
                    lista1.imprimir_banco_de_dados_caminhao();
                }
                std::cout<<"\n\nLista de motorista registrados\n\n\n";
                
                if(lista1.tamanho_banco_de_dados_motorista()==0){
                    
                    std::cout<<"A lista está vazia";
                    
                }
                else{
                    
                    lista1.imprimir_banco_de_dados_motorista();
                    
                }
                
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"Digite 3 para alterar situação de algum motorista";std::cout<<std::endl;
                std::cout<<"Digite 4 para alterar situação de algum caminhão";std::cout<<std::endl;
                std::cout<<"Digite 0 para não alterar situação";std::cout<<std::endl;

                
                int v;
                std::cin>>v;
                
                
                
                if(v==3){
                    if (lista1.tamanho_banco_de_dados_motorista()==0){
                        std::cout<<"\n\nNão é possivel alterar a situção de motorista, o banco de dados está vazio\n";
                    }else{
                        std::cout<<"Digite o CPF do motorista que deseja alterar situação";
                        std::string nome_altera;
                        std::cout<<"Nome: ";
                        std::cin>>nome_altera;
                        lista1.mudar_situacao_motorista(nome_altera);
                        
                        std::cout<<"\n\nLista Atualizada\n\n\n";
                        
                        lista1.imprimir_banco_de_dados_motorista();
                        
                    }
                }
                if(v==4){
                    if (lista1.tamanho_banco_de_dados_caminhao()==0){
                        std::cout<<"\n\nNão é possivel alterar a situção de caminhão, o banco de dados está vazio";
                    }else{
                        std::cout<<"Digite a PLACA do caminhão a alterar situação\n\n";
                        std::string placa_altera;
                        std::cout<<"placa: ";std::cin>>placa_altera;
                        lista1.mudar_situacao_caminhao(placa_altera);
                        
                        
                        std::cout<<"\n\nLista Atualizada\n\n\n";
                        
                        lista1.imprimir_banco_de_dados_caminhao();
                        
                    }
                    
                }
                
                    
                std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
            }
                break;
            case 6:
            {
                lista1.fazer_pedido();
                
            }
                break;
            case 8:
            {
                std::cout<<"\nLista de serviços da "<<nome_empresa<<".\n\n\n";
                
                std::cout<<"Numero de serviços registrados: "<<lista1.tamanho_banco_de_dados_ordem()<<std::endl<<std::endl;
                
                
                std::cout<<"\n\nLista de serviços registrados\n\n\n";
                
                if(lista1.tamanho_banco_de_dados_caminhao()==0){
                    
                    std::cout<<"A lista está vazia";
                    
                }
                else{
                
                
                lista1.imprimir_banco_de_dados_ordem();
                
                }
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
            }
                break;
            case 3:
            {   
                if (lista1.tamanho_banco_de_dados_motorista()==0){
                        std::cout<<"\n\nNão é possivel remover caminhão, o banco de dados está vazio\n";
                }else{
                    
                    std::cout<<"\n\nInsira o CPF do motorista que deseja ser removido:";
                    std::string nome_removido;
                    std::cin>>nome_removido;
                    lista1.remover_motorista(nome_removido);
                
                }
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
            }
                break;
            case 4:
            {
                if (lista1.tamanho_banco_de_dados_caminhao()==0){
                        std::cout<<"\n\nNão é possivel remover caminhão, o banco de dados está vazio\n";
                }else{
                    
                    std::cout<<"\n\nInsira a PLACA do caminhão que deseja ser removido:";
                    std::string placa_removida;
                    std::cin>>placa_removida;
                
                
                    lista1.remover_caminhao(placa_removida);
                }
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
            }
                break;
                
            case 9:
            {
                if (lista1.tamanho_banco_de_dados_ordem()==0){
                        std::cout<<"\n\nNão exite serviço cadastrado para ser removido.\n";
                }else{
                    
                    std::cout<<"\n\nInsira a observacoes do serviço que deseja para ser removido:";
                    std::string observacoes;
                    std::cin>>observacoes;
                
                
                    lista1.remover_ordem(observacoes);
                }
                std::cout<<std::endl;std::cout<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;
            }
                break;
            
                
            case 10:
            {
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
               std::cout<<"                                   CONFIGURAÇÃO ";std::cout<<std::endl<<std::endl;
                std::cout<<"______________________________________________________________________________________________";std::cout<<std::endl;std::cout<<std::endl;
                
                std::cout<<"Mudar nome da empresa\n\n";
                std::cout<<"Novo nome:";std::cin>>nome_empresa;
                
                std::cout<<"\n\n\nNome mudado com sucesso.";
            }
                break;
                
                
            case 11:
                return 0;
            default:
                std::cout<<"opção não encontrada digite novamente\n";
                break;
        }
    }
}
