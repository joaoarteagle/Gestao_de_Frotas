

function goBack() {
    window.history.back();
  }

/*---------------------------------------------------------------------*/
var funcionario={
};
  function cadastrarFuncionario(event){ 
    event.preventDefault(); 
 var nome = document.forms["cadastro"]["nameComplete"].value;
 var data_nascimento = document.forms["cadastro"]["dataNasc"].value;
 var cnh = document.forms["cadastro"]["CNH"].value;
 var login = document.forms["cadastro"]["user"].value;
 var senha = document.forms["cadastro"]["password"].value;
 var cpf = document.forms["cadastro"]["CPF"].value;
 var email = document.forms["cadastro"]["email_user"].value;

 funcionario.Nome = nome;
 funcionario.data_nascimento = data_nascimento;
 funcionario.cnh = cnh;
 funcionario.cpf = cpf;
 funcionario.email = email;
 funcionario.login = login;
 funcionario.senha = senha;
 
 if(funcionario.Nome!=''){
      alert('CADASTRO EFETUADO COM SUCESSO');
      localStorage.setItem('cadastro', JSON.stringify(funcionario));
     window.history.back();
     

    }else{
      alert('PREENCHA TODOS OS CAMPOS COMO REQUISITADO');

    }
  
   
 }     
 

/*---------------------------------------------------------------------*/

/*---------------------------------------------------------------------*/

 function validarDados() {
    var dadosArmazenados = JSON.parse(localStorage.getItem('cadastro'));
    var nome = document.forms["form"]["user"].value;
    var Senha = document.forms["form"]["password"].value;
    var dado = dadosArmazenados.login;
    var dadosenha = dadosArmazenados.senha;
    

    if ((nome != dado)&&(nome !='ADMIN')) {
      var teste = alert('Usuário ou Senha incorretos');
      location.reload();
      return false;
      
    } else if ((Senha != dadosenha)&&(Senha != 'PREFEITURA')) {
      teste = alert('Usuário ou Senha incorretos');
      location.reload();
      return false;
      
    }
 
    return true;
  
  }
  /*---------------------------------------------------------------------*/