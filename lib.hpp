#ifndef lib_hpp
#define lib_hpp

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

namespace final{
    enum class genero:short {MASCULINO, FEMININO, NA};
    
    class data{
        unsigned dia_;
        unsigned mes_;
        unsigned ano_;
    public:
        data();
        data(unsigned novo_dia, unsigned novo_mes, unsigned novo_ano);
        unsigned        get_dia         () const;
        bool            set_dia         (unsigned novo_dia);
        unsigned        get_mes         () const ;
        bool            set_mes         (unsigned novo_mes);
        unsigned        get_ano         () const ;
        void            set_ano         (unsigned novo_ano);
        friend std::ostream& operator<<(std::ostream& saida, const data& data_imprimir);
    };
    std::ostream& operator<<(std::ostream& saida, const data& data_imprimir);

    
    class endereco{
        std::string rua_;
        std::string cidade_;
        std::string estado_;
        std::string pais_;
        std::string cep_;
    public:
        endereco ();
        endereco (std::string n_rua, std::string n_cidade, std::string n_estado, std::string n_pais, std::string n_cep);
        std::string     get_rua     () const;
        void            set_rua     (std::string nova_rua) ;
        std::string     get_cidade  () const;
        void            set_cidade  (std::string nova_cidade) ;
        std::string     get_estado  () const;
        void            set_estado  (std::string novo_estado) ;
        std::string     get_pais    () const;
        void            set_pais    (std::string novo_pais) ;
        std::string     get_cep     () const;
        void            set_cep     (std::string novo_cep) ;
        friend std::ostream& operator<<(std::ostream& saida, const endereco& endereco_imprimir);
    };
    std::ostream& operator<<(std::ostream& saida, const endereco& endereco_imprimir);

    class pessoa{
        std::string     nome_;
        genero          genero_;
        std::string     cpf_;
    public:
        pessoa();
        pessoa(std::string novo_nome, genero novo_genero, std::string novo_cpf);
        std::string get_nome    () const ;
        void        set_nome    (std::string novo_nome);
        std::string get_cpf     () const ;
        void        set_cpf     (std::string novo_cpf);
        genero      get_genero  () const ;
        void        set_genero  (genero novo_genero);
        void        print_pessoa ();
        friend std::ostream& operator<<(std::ostream& saida, const pessoa& pessoa_imprimir);
    };
    std::ostream& operator<<(std::ostream& saida, const pessoa& pessoa_imprimir);
    
    class motorista: public pessoa{
        unsigned        anos_experiencia;
        std::string     num_carteira;
        data            vencimento_carteira;
        bool status; // se verdadeiro está ocupado e não poderá ser usado
    public:
        motorista();
        motorista(unsigned n_anos_exp, std::string n_num_carteira, data n_vencimento, bool n_status, std::string n_nome, genero n_genero, std::string n_cpf);
        void        set_anos_exp            (unsigned n_anos_exp);
        unsigned    get_anos_exp            ()const;
        void        set_num_carteira        (std::string n_num_carteira);
        std::string get_num_carteira        ()const ;
        void        set_vencimento_carteira  (data n_vencimento);
        data        get_vencimento_carteira ()const;
        void        set_status              (bool n_status);
        bool        get_status              ()const;
        long unsigned int situacao();
        friend std::ostream& operator<<(std::ostream& saida, const motorista& motorista_imprimir);
    };
    std::ostream& operator<<(std::ostream& saida, const motorista& motorista_imprimir);

    
    class veiculo{
        std::string placa;
        std::string renavam;
        data        ultima_revisao;
    public:
        veiculo();
        veiculo(std::string n_placa, std::string n_renavam, data n_ultima_revisao);
        void        set_placa          (std::string n_placa);
        std::string get_placa          ()const;
        void        set_renavam        (std::string n_renavam);
        std::string get_renavam        ()const;
        void        set_ultima_revisao (data n_ultima_revisao);
        data        get_ultima_revisao ()const;
        friend std::ostream& operator<<(std::ostream& saida, veiculo& veiculo_imprimir);
    };
    std::ostream& operator<<(std::ostream& saida, veiculo& veiculo_imprimir);
    
    class caminhao: public veiculo{
        std::string modelo;
        unsigned    id_empresa;
        bool        status; // se verdadeiro está ocupado e não poderá ser usado
    public:
        caminhao();
        caminhao(std::string n_modelo, unsigned n_id, bool n_status, std::string n_placa, std::string n_renavam, data n_ultima_revisao);
        void        set_modelo  (std::string n_modelo);
        std::string get_modelo  ()const;
        void        set_id      (unsigned n_id);
        unsigned    get_id      ()const;
        void        set_status  (bool n_status);
        bool        get_status  ()const;
        long unsigned int         situacao();
        void imprimir_caminhao();
        
        friend std::ostream& operator<<(std::ostream& saida, caminhao& caminhao_imprimir);
    };
    std::ostream& operator<<(std::ostream& saida, caminhao& caminhao_imprimir);


    class ordem {
        data        data_saida_;
        data        data_chegada_;
        motorista   motorista_usado;
        caminhao    caminhao_usado;
        std::string observacoes;
        
    public:
        ordem();
        ordem(data n_data_saida, data n_data_chegada, motorista n_motorista_usado, caminhao n_caminhao_usado, std::string n_observacoes);
        void set_data_saida (data n_data_saida);
        data get_data_saida ()const;
        void set_data_chegada (data n_data_chegada);
        data get_data_chegada ()const;
        bool set_motorista_usado (motorista n_motorista_usado);
        motorista get_motorista_usado ()const;
        bool set_caminhao_usado (caminhao n_caminhao_usado);
        caminhao get_caminhao_usado ()const;
        void set_observacoes (std::string n_observacoes);
        std::string get_observacoes ()const;
        int protocolo();
        friend std::ostream& operator<<(std::ostream& saida, ordem& ordem_imprimir);
    };
    std::ostream& operator<<(std::ostream& saida, ordem& ordem_imprimir);
    
//--------------------------------------------------------------------------------------------------------------------------------//
    class Lista_geral{
     
    private:
    std::vector<final::motorista> banco_de_dados_motorista;
    std::vector<final::caminhao> banco_de_dados_caminhao;
    std::vector<final::ordem> banco_de_dados_ordem;
    protected:
        
        
    long unsigned int tam;
    long unsigned int t;
    long unsigned int dum;
    long unsigned int indice_cam;
    int contador_cam=0;
    long unsigned int indice;
    int contador=0;
    public:

           Lista_geral();
           void insere_caminhao(std::string mo, unsigned ida, bool situacao, std::string placa, std::string renavam, final::data revisao);
           void insere_motorista(unsigned anos_exp, std::string num_carteira, data vencimento, bool status, std::string nome, genero genero, std::string cpf);
           void insere_ordem(data data_saida, data data_chegada, std::string observacoes);
           long unsigned int tamanho_banco_de_dados_caminhao();
           long unsigned int tamanho_banco_de_dados_motorista();
           long unsigned int tamanho_banco_de_dados_ordem();
           void imprimir_banco_de_dados_caminhao();
           void imprimir_banco_de_dados_motorista();
           void imprimir_banco_de_dados_ordem();
           void fazer_pedido();
           void mudar_situacao_motorista(std::string cpf_muda);
           void mudar_situacao_caminhao(std::string placa_remo);
           void remover_motorista(std::string cpf_remo);
           void remover_caminhao(std::string placa_remo);
           void remover_ordem(std::string nome_remo);
           int tamanho_motorista_disponivel();
           int tamanho_caminhao_disponivel();
           int tamanho_motorista_n_disponivel();
           int tamanho_caminhao_n_disponivel();
           
           
            
        
    
    };
}

#endif

