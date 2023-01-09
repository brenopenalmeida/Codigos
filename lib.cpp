#include "lib.hpp"
#include <vector>
#include <queue>
final::data::data() : dia_{1}, mes_{1}, ano_{1} {}
final::data::data(unsigned novo_dia, unsigned novo_mes, unsigned novo_ano) : data()
{
    set_mes(novo_mes);
    set_ano(novo_ano);
    set_dia(novo_dia);
}
unsigned final::data::get_dia() const
{
    return dia_;
}
bool final::data::set_dia(unsigned novo_dia)
{
    bool bissexto = false;
    if ((ano_ % 4 == 0 && ano_ % 100 != 0) || ano_ % 400 == 0)
        bissexto = true;

    if (mes_ == 2 && bissexto)
    {
        if (novo_dia > 29)
            return true;
        dia_ = novo_dia;
    }
    else if (mes_ == 2)
    {
        if (novo_dia > 28)
            return true;
        dia_ = novo_dia;
    }
    else if (mes_ == 1 || mes_ == 3 || mes_ == 5 || mes_ == 7 || mes_ == 8 || mes_ == 10 || mes_ == 12)
    {
        if (novo_dia > 31)
            return true;
        dia_ = novo_dia;
    }
    else
    {
        if (novo_dia > 30)
            return true;
        dia_ = novo_dia;
    }
    return false;
}
unsigned final::data::get_mes() const
{
    return mes_;
}
bool final::data::set_mes(unsigned novo_mes)
{
    if (novo_mes > 12)
        return true;
    mes_ = novo_mes;
    return false;
}
unsigned final::data::get_ano() const
{
    return ano_;
}
void final::data::set_ano(unsigned novo_ano)
{
    ano_ = novo_ano;
}
std::ostream & final::operator<<(std::ostream &saida, const data &data_imprimir)
{
    saida << std::setw(2) << std::setfill('0') << data_imprimir.dia_ << "/" << std::setw(2) << std::setfill('0') << data_imprimir.mes_ << "/" << std::setw(4) << std::setfill('0') << data_imprimir.ano_ << "\n";
    return saida;
}

final::endereco::endereco() : rua_{"---"}, cidade_{"---"}, estado_{"---"}, pais_{"---"}, cep_{"00000000"} {}

final::endereco::endereco(std::string n_rua, std::string n_cidade, std::string n_estado, std::string n_pais, std::string n_cep) : endereco()
{
    set_rua(n_rua);
    set_cidade(n_cidade);
    set_estado(n_estado);
    set_pais(n_pais);
    set_cep(n_cep);
}
std::string final::endereco::get_rua() const
{
    return rua_;
}
void final::endereco::set_rua(std::string nova_rua)
{
    rua_ = nova_rua;
}
std::string final::endereco::get_cidade() const
{
    return cidade_;
}
void final::endereco::set_cidade(std::string nova_cidade)
{
    cidade_ = nova_cidade;
}
std::string final::endereco::get_estado() const
{
    return estado_;
}
void final::endereco::set_estado(std::string novo_estado)
{
    estado_ = novo_estado;
}
std::string final::endereco::get_pais() const
{
    return pais_;
}
void final::endereco::set_pais(std::string novo_pais)
{
    pais_ = novo_pais;
}
std::string final::endereco::get_cep() const
{
    return cep_;
}
void final::endereco::set_cep(std::string novo_cep)
{
    unsigned long int length = novo_cep.length();
    if (length != 8)
        return;
    for (unsigned long i = 0; i < length; i++)
    {
        if (!std::isdigit(novo_cep[i]))
            return;
    }
    cep_ = novo_cep;
}
std::ostream & final::operator<<(std::ostream &saida, const endereco &endereco_imprimir)
{
    saida << "Rua   : " << endereco_imprimir.rua_ << "\n";
    saida << "Cidade: " << endereco_imprimir.cidade_ << "\n";
    saida << "Estado: " << endereco_imprimir.estado_ << "\n";
    saida << "País  : " << endereco_imprimir.pais_ << "\n";
    saida << "CEP   : " << endereco_imprimir.cep_ << "\n";
    return saida;
}

final::pessoa::pessoa() : nome_{"---"}, genero_{genero::NA}, cpf_{"00000000000"} {}
final::pessoa::pessoa(std::string novo_nome, genero novo_genero, std::string novo_cpf) : pessoa()
{
    nome_ = novo_nome;
    genero_ = novo_genero;
    set_cpf(novo_cpf);
}
std::string final::pessoa::get_nome() const
{
    return nome_;
}
void final::pessoa::set_nome(std::string novo_nome)
{
    nome_ = novo_nome;
}
std::string final::pessoa::get_cpf() const
{
    return cpf_;
}
void final::pessoa::set_cpf(std::string novo_cpf)
{
    unsigned long int length = novo_cpf.length();
    if (length != 11)
        return;
    for (unsigned long i = 0; i < length; i++)
    {
        if (!std::isdigit(novo_cpf[i]))
            return;
    }
    cpf_ = novo_cpf;
}
final::genero final::pessoa::get_genero() const
{
    return genero_;
}
void final::pessoa::set_genero(genero novo_genero)
{
    genero_ = novo_genero;
}

std::ostream & final::operator<<(std::ostream &saida, const pessoa &pessoa_imprimir)
{
    saida << "Nome   : " << pessoa_imprimir.nome_ << "\n";
    saida << "CPF    : " << pessoa_imprimir.cpf_ << "\n";
    saida << "Gênero : ";

    genero hld = pessoa_imprimir.get_genero();
    switch (hld)
    {
    case genero::MASCULINO:
        saida << "M\n";
        break;
    case genero::FEMININO:
        saida << "F\n";
        break;
    default:
        saida << "N/A\n";
        break;
    }
    return saida;
}

final::motorista::motorista() : pessoa(), anos_experiencia{0}, num_carteira{"00000000000"}, vencimento_carteira{1, 1, 1}, status{false} {}
final::motorista::motorista(unsigned n_anos_exp, std::string n_num_carteira, data n_vencimento, bool n_status, std::string n_nome, genero n_genero, std::string n_cpf)
{
    anos_experiencia = n_anos_exp;
    set_num_carteira(n_num_carteira);
    vencimento_carteira = n_vencimento;
    set_nome(n_nome);
    set_genero(n_genero);
    set_cpf(n_cpf);
    status = n_status;
}

void final::motorista::set_anos_exp(unsigned n_anos_exp)
{
    anos_experiencia = n_anos_exp;
}
unsigned final::motorista::get_anos_exp() const
{
    return anos_experiencia;
}
void final::motorista::set_num_carteira(std::string n_num_carteira)
{
    unsigned long int length = n_num_carteira.length();
    if (length != 11)
        return;
    for (unsigned long i = 0; i < length; i++)
    {
        if (!std::isdigit(n_num_carteira[i]))
            return;
    }
    num_carteira = n_num_carteira;
}
std::string final::motorista::get_num_carteira() const
{
    return num_carteira;
}
void final::motorista::set_vencimento_carteira(data n_vencimento)
{
    vencimento_carteira = n_vencimento;
}
final::data final::motorista::get_vencimento_carteira() const
{
    return vencimento_carteira;
}
void final::motorista::set_status(bool n_status)
{
    status = n_status;
}
bool final::motorista::get_status() const
{
    return status;
}

long unsigned int final::motorista::situacao()
{

    bool z = get_status();
    if (z == true)
    {

        //std::cout<<"Motorista em serviço";
        return 1;
    }
    else
    {

        //std::cout<<"Motorista sem serviço";
        return 0;
    }
}
std::ostream & final::operator<<(std::ostream &saida, const motorista &motorista_imprimir)
{

    saida << "Nome   : " << motorista_imprimir.get_nome() << "\n";
    saida << "CPF    : " << motorista_imprimir.get_cpf() << "\n";
    saida << "Gênero : ";
    genero hld = motorista_imprimir.get_genero();
    switch (hld)
    {
    case genero::MASCULINO:
        saida << "M\n";
        break;
    case genero::FEMININO:
        saida << "F\n";
        break;
    default:
        saida << "N/A\n";
        break;
    }
    saida << "Experiência         : " << motorista_imprimir.anos_experiencia << " anos\n";
    saida << "Carteira            : " << motorista_imprimir.num_carteira << "\n";
    saida << "Vencimento carteira : " << motorista_imprimir.vencimento_carteira;

    if (motorista_imprimir.get_status() == true)
    {

        saida << "Situacao: Em serviço "
              << "\n";
    }
    else
    {
        saida << "Situacao: Sem serviço "
              << "\n";
    }
    return saida;
}

final::veiculo::veiculo() : placa{"0000000"}, renavam{"000000000"}, ultima_revisao{1, 1, 1} {}
final::veiculo::veiculo(std::string n_placa, std::string n_renavam, data n_ultima_revisao)
{
    set_placa(n_placa);
    set_renavam(n_renavam);
    set_ultima_revisao(n_ultima_revisao);
}
void final::veiculo::set_placa(std::string n_placa)
{
    if (n_placa.length() != 7)
        return;
    placa = n_placa;
}
std::string final::veiculo::get_placa() const
{
    return placa;
}
void final::veiculo::set_renavam(std::string n_renavam)
{
    if (n_renavam.length() != 9)
        return;
    renavam = n_renavam;
}
std::string final::veiculo::get_renavam() const
{
    return renavam;
}
void final::veiculo::set_ultima_revisao(final::data n_ultima_revisao)
{
    ultima_revisao = n_ultima_revisao;
}
final::data final::veiculo::get_ultima_revisao() const
{
    return ultima_revisao;
}
std::ostream & final::operator<<(std::ostream &saida, final::veiculo &veiculo_imprimir)
{
    saida << "Placa  : " << veiculo_imprimir.placa << "\n";
    saida << "Renavam: " << veiculo_imprimir.renavam << "\n";
    saida << "Última revisão: " << veiculo_imprimir.ultima_revisao;
    return saida;
}
final::caminhao::caminhao() : veiculo(), modelo{"---"}, id_empresa{0}, status{false} {}
final::caminhao::caminhao(std::string n_modelo, unsigned n_id, bool n_status, std::string n_placa, std::string n_renavam, data n_ultima_revisao) : modelo{n_modelo}, id_empresa(n_id)
{
    set_placa(n_placa);
    set_renavam(n_renavam);
    set_ultima_revisao(n_ultima_revisao);
    set_status(n_status);
}
void final::caminhao::set_modelo(std::string n_modelo)
{
    modelo = n_modelo;
}
std::string final::caminhao::get_modelo() const
{
    return modelo;
}
void final::caminhao::set_id(unsigned n_id)
{
    id_empresa = n_id;
}
unsigned final::caminhao::get_id() const
{
    return id_empresa;
}
void final::caminhao::set_status(bool n_status)
{
    status = n_status;
}
bool final::caminhao::get_status() const
{
    return status;
}
long unsigned int final::caminhao::situacao()
{

    bool a = get_status();
    if (a == true)
    {

        //std::cout<<"Caminhão há serviço";
        return 1;
    }
    else
    {

        //std::cout<<"Caminhão sem serviço";
        return 0;
    }
}
void final::caminhao::imprimir_caminhao()
{

    std::cout << "Modelo        : ";
    get_modelo();
    std::cout << "\n";
    std::cout << "ID            : ";
    get_id();
    std::cout << "\n";
    std::cout << "Status:         ";
    get_status();
    std::cout << "\n";
}
std::ostream & final::operator<<(std::ostream &saida, caminhao &caminhao_imprimir)
{
    saida << "Placa         : " << caminhao_imprimir.get_placa() << "\n";
    saida << "Renavam       : " << caminhao_imprimir.get_renavam() << "\n";
    saida << "Modelo        : " << caminhao_imprimir.modelo << "\n";
    saida << "ID            : " << caminhao_imprimir.id_empresa << "\n";
    saida << "Última revisão: " << caminhao_imprimir.get_ultima_revisao();
    //saida<<"Status: "<<std::boolalpha<<caminhao_imprimir.status<<"\n";
    if (caminhao_imprimir.get_status() == true)
    {

        saida << "Situacao: Em serviço "
              << "\n";
    }
    else
    {
        saida << "Situacao: Sem serviço "
              << "\n";
    }

    return saida;
}
final::ordem::ordem() : data_saida_{1, 1, 1}, data_chegada_{2, 2, 2}, motorista_usado{}, caminhao_usado{}, observacoes{"---"} {}
final::ordem::ordem(data n_data_saida, data n_data_chegada, motorista n_motorista_usado, caminhao n_caminhao_usado, std::string n_observacoes)
{
    set_data_saida(n_data_saida);
    set_data_chegada(n_data_chegada);
    set_motorista_usado(n_motorista_usado);
    set_caminhao_usado(n_caminhao_usado);
    set_observacoes(n_observacoes);
}
void final::ordem::set_data_saida(data n_data_saida)
{
    data_saida_ = n_data_saida;
}
final::data final::ordem::get_data_saida() const
{
    return data_saida_;
}
void final::ordem::set_data_chegada(data n_data_chegada)
{
    data_chegada_ = n_data_chegada;
}
final::data final::ordem::get_data_chegada() const
{
    return data_chegada_;
}
bool final::ordem::set_motorista_usado(motorista n_motorista_usado)
{
    if (n_motorista_usado.get_status() == true)
        return false; //se motorista ocupado ele estará com status true e nao poderá entrar na ordem e será retornado false
    motorista_usado = n_motorista_usado;
    n_motorista_usado.set_status(true);
    return true;
}
final::motorista final::ordem::get_motorista_usado() const
{
    return motorista_usado;
}
bool final::ordem::set_caminhao_usado(caminhao n_caminhao_usado)
{
    if (n_caminhao_usado.get_status() == true)
        return false;
    caminhao_usado = n_caminhao_usado;
    n_caminhao_usado.set_status(true);
    return true;
}
final::caminhao final::ordem::get_caminhao_usado() const
{
    return caminhao_usado;
}
void final::ordem::set_observacoes(std::string n_observacoes)
{
    observacoes = n_observacoes;
}
std::string final::ordem::get_observacoes() const
{
    return observacoes;
}
std::ostream & final::operator<<(std::ostream &saida, ordem &ordem_imprimir)
{
    saida << "Impressão Ordem: \n";
    saida << "Frete          : " << ordem_imprimir.observacoes        << "\n\n";
    saida << "Data de saida  : " << ordem_imprimir.data_saida_;
    saida << "Data de chegada: " << ordem_imprimir.data_chegada_      << "\n";
    //saida << "Motorista usado: \n" << ordem_imprimir.motorista_usado  << "\n";
    //saida << "Caminhão usado : \n" << ordem_imprimir.caminhao_usado   << "\n";
    return saida;
}


//--------------------------------------------------------------------------------------------------------------------------------//
final::Lista_geral::Lista_geral(){

}
void final::Lista_geral::insere_caminhao(std::string mo, unsigned ida, bool situacao, std::string placa, std::string renavam, data revisao)
{

    final::caminhao caminhao_temp;

    caminhao_temp.set_placa(placa);
    caminhao_temp.set_renavam(renavam);
    caminhao_temp.set_modelo(mo);
    caminhao_temp.set_ultima_revisao(revisao);
    caminhao_temp.set_status(situacao);
    caminhao_temp.set_id(ida);

    banco_de_dados_caminhao.push_back(caminhao_temp);
}

void final::Lista_geral::insere_motorista(unsigned anos_exp, std::string num_carteira, data vencimento, bool status, std::string nome, genero genero, std::string cpf)
{

    final::motorista motorista_temp;

    motorista_temp.set_anos_exp(anos_exp);
    motorista_temp.set_num_carteira(num_carteira);
    motorista_temp.set_vencimento_carteira(vencimento);
    motorista_temp.set_status(status);
    motorista_temp.set_nome(nome);
    motorista_temp.set_genero(genero);
    motorista_temp.set_cpf(cpf);

    banco_de_dados_motorista.push_back(motorista_temp);
}
void final::Lista_geral::insere_ordem(data data_saida, data data_chegada, std::string observacoes)
{

    final::ordem ordem_temp;

    ordem_temp.set_data_saida(data_saida);
    ordem_temp.set_data_chegada(data_chegada);
    //ordem_temp.set_motorista_usado(motorista_usado);
    //ordem_temp.set_caminhao_usado(caminhao_usado);
    ordem_temp.set_observacoes(observacoes);

    banco_de_dados_ordem.push_back(ordem_temp);
}
long unsigned int final::Lista_geral::tamanho_banco_de_dados_caminhao()
{

    dum = banco_de_dados_caminhao.size();
    return dum;
}

long unsigned int final::Lista_geral::tamanho_banco_de_dados_motorista()
{

    tam = banco_de_dados_motorista.size();
    return tam;
}
long unsigned int final::Lista_geral::tamanho_banco_de_dados_ordem()
{

    t = banco_de_dados_ordem.size();
    return t;
}
void final::Lista_geral::imprimir_banco_de_dados_caminhao(){
    auto max=tamanho_banco_de_dados_caminhao();
    for (long unsigned b=0; b<max; b++){
        std::cout << std::endl;
        std::cout << banco_de_dados_caminhao[b];
    }
}
void final::Lista_geral::imprimir_banco_de_dados_ordem(){
    auto max=tamanho_banco_de_dados_ordem();
    for (long unsigned b=0; b<max; b++){
        std::cout << std::endl;
        std::cout << banco_de_dados_ordem[b];
    }
}
void final::Lista_geral::imprimir_banco_de_dados_motorista(){
    auto max=tamanho_banco_de_dados_motorista();
    for (long unsigned b=0; b<max; b++){
        std::cout << std::endl;
        std::cout << banco_de_dados_motorista[b];
    }
}
void final::Lista_geral::fazer_pedido()
{
    if (tamanho_banco_de_dados_ordem() == 0)
    {

        std::cout << "\n\nNão é possivel realizar pedido, sem ordens registradas." <<std::endl<< std::endl;
    }
    else
    {

        if ((tamanho_banco_de_dados_caminhao() == 0) || (tamanho_banco_de_dados_motorista() == 0))
        {

            std::cout << "\n\nNão é possivel realizar esse serviço, pois não possui motoristas ou caminhões registrado. " <<std::endl<< std::endl;
        }
        else
        {

            bool verificar;
            bool verificar_cam;
            bool verificar_cam_cam;
            bool verificar_cam_cam_cam;
            int contador_mot_in=0;
            int contador_cam_in=0;

            auto max=tamanho_banco_de_dados_motorista();
            for (long unsigned b=0; b<max; b++){
    

                verificar = banco_de_dados_motorista[b].get_status();

                if (verificar == false)
                {

                    indice = b;
                    break;
                }
            }

            auto maax=tamanho_banco_de_dados_caminhao();
            for (long unsigned c=0; c<maax; c++){
    

                verificar_cam = banco_de_dados_caminhao[c].get_status();

                if (verificar_cam == false)
                {

                    indice_cam = c;
                    break;
                }
            }

            auto maxx=tamanho_banco_de_dados_motorista();
            for (long unsigned d=0; d<maxx; d++){
    

                verificar_cam_cam = banco_de_dados_motorista[d].get_status();

                if (verificar_cam_cam == false)
                {

                    contador_mot_in++;
                }
            }

            auto mmax=tamanho_banco_de_dados_caminhao();
            for (long unsigned e=0; e<mmax; e++){
    

                verificar_cam_cam_cam = banco_de_dados_caminhao[e].get_status();

                if (verificar_cam_cam_cam == false)
                {

                    contador_cam_in++;
                }
            }

            if ((contador_cam_in >= 1) && (contador_mot_in >= 1))
            {

                std::cout << "\n______________________________________________________________________________________________________\n\n";

                std::cout << "\nOrdem de serviço aberta:";

                std::cout << "\n______________________________________________________________________________________________________\n";
                std::cout << "\n\n";
                std::cout << banco_de_dados_ordem[0];

                std::cout << "\n______________________________________________________________________________________________________\n";
                
                std::cout << "\n\nDados motorista:\n\n";
                std::cout << banco_de_dados_motorista[indice];

                std::cout << "\n______________________________________________________________________________________________________\n\n";
                std::cout << "\n\nDados Caminhão:\n\n";
                std::cout << banco_de_dados_caminhao[indice_cam];

                std::cout << "\n______________________________________________________________________________________________________\n";

                banco_de_dados_motorista[indice].set_status(true);
                banco_de_dados_caminhao[indice_cam].set_status(true);

                //banco_de_dados_motorista.insert(banco_de_dados_motorista.begin() + indice, moto.set_status(true));
                //banco_de_dados_caminhao.erase(banco_de_dados_caminhao.begin() + indice_cam);
                banco_de_dados_ordem.erase(banco_de_dados_ordem.begin());
                contador=contador_mot_in-1;
                contador_cam=contador_cam_in-1;
            }

            else if ((contador_cam_in== 0) && (contador_mot_in >= 1))
            {

                std::cout << "\n\nNão possui caminhões disponíveis;\n\n";
            }

            else if ((contador_cam_in >= 1) && (contador_mot_in == 0))
            {

                std::cout << "\n\nNão possui motoristas disponíveis\n\n";
            }

            else
            {

                std::cout << "\n\nNão possui motoristas e caminhões disponíveis\n";
            }
        }
    }
}
void final::Lista_geral::mudar_situacao_motorista(std::string cpf_muda)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int f = 0;
    std::string cpff;
    long unsigned d;
    std::string nome_remo;
    auto max=tamanho_banco_de_dados_motorista();
    for ( d=0; d<max; d++){
    

        cpff = banco_de_dados_motorista[d].pessoa::get_cpf();

        if (cpf_muda == cpff)
        {

            if (banco_de_dados_motorista[d].get_status() == true)
            {
                nome_remo = banco_de_dados_motorista[d].pessoa::get_nome();
                    
                banco_de_dados_motorista[d].set_status(false);
                a++;
                if (banco_de_dados_motorista[d].pessoa::get_genero() == genero::MASCULINO)
                {

                    c++;
                    break;
                }

                break;
            }
            else
            {
                nome_remo = banco_de_dados_motorista[d].pessoa::get_nome();
                    
                banco_de_dados_motorista[d].set_status(true);
                b++;
                if (banco_de_dados_motorista[d].pessoa::get_genero() == genero::MASCULINO)
                {
                    f++;
                    break;
                }
                break;
            }
        }
    }
   // std::string nome_remo;

    
    if (c != 0)
    {

        std::cout << "\n\nA situacao do motorista " << nome_remo << " foi mudada para Sem serviço.";
    }
    else if (a != 0)
    {

        std::cout << "\n\nA situacao da motorista " << nome_remo << " foi mudada para Sem serviço.";
    }
    else if (f != 0)
    {

        std::cout << "\n\nA situacao do motorista " << nome_remo << " foi mudada para Em serviço.";
    }
    else if (b != 0)
    {

        std::cout << "\n\nA situacao da motorista " << nome_remo << " foi mudada para Em serviço.";
    }
    else
    {

        std::cout << "Não foi encontrado motoristas com o CPF " << nome_remo << " no sistema.";
    }
}
void final::Lista_geral::mudar_situacao_caminhao(std::string placa_remo)
{
    int a = 0;
    int b = 0;
    std::string nome;
    auto max=tamanho_banco_de_dados_caminhao();
    for (long unsigned d=0; d<max; d++){
    

        nome = banco_de_dados_caminhao[d].veiculo::get_placa();

        if (placa_remo == nome)
        {

            if (banco_de_dados_caminhao[d].get_status() == true)
            {

                a++;
                banco_de_dados_caminhao[d].set_status(false);
                break;
            }
            else
            {
                b++;
                banco_de_dados_caminhao[d].set_status(true);
                break;
            }
        }
    }
    if (a != 0)
    {

        std::cout << "\n\nA situação do caminhão com a placa " << placa_remo << " foi mudada para Sem serviço.";
    }
    else if (b != 0)
    {

        std::cout << "\n\nA situação do caminhão com a placa " << placa_remo << " foi mudada para Em serviço.";
    }
    else
    {

        std::cout << "\n\nNão foi encontrado caminhão com a placa " << placa_remo << " no sistema.";
    }
}

void final::Lista_geral::remover_caminhao(std::string placa_remo)
{
    int a = 0;
    std::string nome;
    auto max=tamanho_banco_de_dados_caminhao();
    for (long unsigned d=0; d<max; d++){
    

        nome = banco_de_dados_caminhao[d].get_placa();

        if (placa_remo == nome)
        {
            a++;
            banco_de_dados_caminhao.erase(banco_de_dados_caminhao.begin() + static_cast<long int> (d));
            break;
        }
    }
    if (a != 0)
    {

        std::cout << "O caminhão relacionado a placa " << placa_remo << " foi removida do sistema.";
    }
    else
    {

        std::cout << "Não foi encontrado caminhões com a placa " << placa_remo << " no sistema.";
    }
}

void final::Lista_geral::remover_motorista(std::string cpf_remo)
{
    std::string cpff;
    std::string nome_remo;
    int a = 0;
    int b = 0;
    long unsigned d;
    auto max=tamanho_banco_de_dados_motorista();
    for (d=0; d<max; d++){
    

        cpff = banco_de_dados_motorista[d].pessoa::get_cpf();

        if (cpf_remo == cpff)
        {   
            nome_remo = banco_de_dados_motorista[d].pessoa::get_nome();
            a++;
            banco_de_dados_motorista.erase(banco_de_dados_motorista.begin() + static_cast<long int> (d));

            if (banco_de_dados_motorista[d].pessoa::get_genero() == genero::MASCULINO)
            {
                b++;
                

                break;
            }
            break;
        }
    }
    

    if (b != 0)
    {

        std::cout << "O motorista " << nome_remo << " foi removida do sistema.\n\n";
    }
    else if (a != 0)
    {

        std::cout << "A motorista " << nome_remo << " foi removida do sistema.\n\n";
    }
    else
    {

        std::cout << "Não foi encontrado motoristas com o CPF " << cpf_remo << " no sistema.";
    }
}

void final::Lista_geral::remover_ordem(std::string nome_remo)
{
    std::string nome;
    int a = 0;
    auto max=tamanho_banco_de_dados_ordem();
    for (long unsigned d=0; d<max; d++){
    
        nome = banco_de_dados_ordem[d].get_observacoes();

        if (nome_remo == nome)
        {
            a++;
            banco_de_dados_ordem.erase(banco_de_dados_ordem.begin() + static_cast<long int> (d));
            break;
        }
    }
    if (a != 0)
    {

        std::cout << "A ordem " << nome_remo << " foi removida do sistema.";
    }
    else
    {

        std::cout << "Não foi encontrado ordens com o nome " << nome_remo << "  no sistema..";
    }
}
 int final::Lista_geral::tamanho_motorista_disponivel()
{
    int k=0;

    auto max=tamanho_banco_de_dados_motorista();
    for (long unsigned b=0; b<max; b++){
    
        if (banco_de_dados_motorista[b].get_status() == false)
            {

                k++;
        }
    }
    return k;
}
int final::Lista_geral::tamanho_caminhao_disponivel()
{
    int k=0;

    auto max=tamanho_banco_de_dados_caminhao();
    for (long unsigned b=0; b<max; b++){
    
        if (banco_de_dados_caminhao[b].get_status() == false)
            {

                k++;

        }
    }
    return k;
}
int final::Lista_geral::tamanho_motorista_n_disponivel()
{
    int k=0;

    auto max=tamanho_banco_de_dados_motorista();
    for (long unsigned b=0; b<max; b++){
    
        if (banco_de_dados_motorista[b].get_status() == true)
            {

                k++;
        }
    }
    return k;
}
int final::Lista_geral::tamanho_caminhao_n_disponivel()
{
    int k=0;

    auto max=tamanho_banco_de_dados_caminhao();
    for (long unsigned b=0; b<max; b++){
    
        if (banco_de_dados_caminhao[b].get_status() == true)
            {

                k++;

        }
    }
    return k;
}

    
    

