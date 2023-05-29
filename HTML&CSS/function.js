var erro=0;

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
 
 if(funcionario.Nome!=' '){
 

      alert('CADASTRO EFETUADO COM SUCESSO');
      localStorage.setItem('cadastro', JSON.stringify(funcionario));
     window.history.back();
     

    }else{
      alert('PREENCHA TODOS OS CAMPOS COMO REQUISITADO');

    }
  
   
 }     
 

/*---------------------------------------------------------------------*/
var veiculo={
};
  function cadastrarVeiculo(event){ 
    event.preventDefault(); 
 var NomeVeiculo = document.forms["cadastroVec"]["NomeVeiculo"].value;
 var MarcaVeiculo = document.forms["cadastroVec"]["MarcaVeiculo"].value;
 var idade = document.forms["cadastroVec"]["IdadeVeiculo"].value; 
 var placaVeiculo = document.forms["cadastroVec"]["placaVeiculo"].value;
 var Quilometragem = document.forms["cadastroVec"]["Quilometragem"].value;
 var ModeloVeiculo = document.forms["cadastroVec"]["ModeloVeiculo"].value;


 veiculo.NomeVeiculo = NomeVeiculo;
 veiculo.MarcaVeiculo = MarcaVeiculo;
 veiculo.idade = idade;
 veiculo.placaVeiculo = placaVeiculo;
 veiculo.Quilometragem = Quilometragem;
 veiculo.ModeloVeiculo = ModeloVeiculo;
 
 
 if(veiculo.NomeVeiculo!=' '){
  console.log(veiculo.NomeVeiculo);
  console.log(veiculo.MarcaVeiculo);
  console.log(veiculo.idade);
  console.log(veiculo.placaVeiculo);
  console.log(veiculo.Quilometragem);
  console.log(veiculo.ModeloVeiculo);
      alert('CADASTRO EFETUADO COM SUCESSO');
      localStorage.setItem('cadastroVec', JSON.stringify(veiculo));
     novoVeiculo();

    }else{
      alert('PREENCHA TODOS OS CAMPOS COMO REQUISITADO');

    }
  
   
 } 
 function novoVeiculo(){
 var divElement = document.getElementsByClassName("textdes");
 var dadosArmazenados = JSON.parse(localStorage.getItem('cadastroVec'));

 divElement.textontent = "Nome: " + dadosArmazenados.NomeVeiculo + "<br>Marca: " + dadosArmazenados.MarcaVeiculo;
}
/*---------------------------------------------------------------------*/

 function validarDados() {
    var dadosArmazenados = JSON.parse(localStorage.getItem('cadastro'));
    var nome = document.forms["form"]["user"].value;
    var Senha = document.forms["form"]["password"].value;
    var dado = dadosArmazenados.login;
    var dadosenha = dadosArmazenados.senha;
    
    

    if ((nome != dado)&&(nome !='ADMIN')) {
      erro++;
      var teste = alert('Usuário ou Senha incorretos \nQuantidade de erros: '+ erro );
      if(erro==3){
        window.open('file:///C:/Users/Usuario/Desktop/Desafio_Profissional/HTML&CSS/erro.html','_self');
      }
     
     // window.open('file:///C:/Users/Usuario/Desktop/Desafio_Profissional/HTML&CSS/erro.html','_self');
      //location.reload();
      return false;
      
    } else if ((Senha != dadosenha)&&(Senha != 'PREFEITURA')) {
      erro++;
      teste = alert('Usuário ou Senha incorretos <br> Você errou '+ erro);
     
      if(erro==3){
        window.open('file:///C:/Users/Usuario/Desktop/Desafio_Profissional/HTML&CSS/erro.html','_self');
  
      }
      //window.open('file:///C:/Users/Usuario/Desktop/Desafio_Profissional/HTML&CSS/erro.html','_self');
     // location.reload();
      return false;
      
    }
    
    erro=0;
    return true;
  
  }
  /*---------------------------------------------------------------------*/