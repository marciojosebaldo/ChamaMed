#language: pt
  Funcionalidade: testar o cadastro de um colaborador
    Cenário: cadastrar um colaborador
      Dado que estou na tela inicial
      Quando clico na opção Colaboradores
      E adiciono no campo colaborador
      E preencho nome, data de nascimento, CPF e descrição da função
      E clico em salvar o colaborador
      Entao o banco de dados armazena os dados lançados