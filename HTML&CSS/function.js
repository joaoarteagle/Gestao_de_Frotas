function goBack() {
    window.history.back();
  }



  function cadastrar(){ 
  alert('CADASTRO EFETUADO COM SUCESSO');
  window.history.back();
 }     



 function validarDados() {
    var nome = document.forms["form"]["user"].value;
    var Senha = document.forms["form"]["password"].value;


    if (nome != 'ADMIN') {
      var teste = alert('Usuário ou Senha incorretos');
      location.reload();
      return false;

    } else if (Senha != 'PREFEITURA') {
      teste = alert('Usuário ou Senha incorretos');
      location.reload();
      return false;

    }
    return true;
  }