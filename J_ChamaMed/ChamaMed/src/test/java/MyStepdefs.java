import org.openqa.selenium.WebDriver;
import org.openqa.selenium.edge.EdgeDriver;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import java.awt.*;

public class MyStepdefs {
    private WebDriver driver;

    @BeforeMethod
    // Define o navegador e o diretório do webdriver
    public void iniciar() {
        System.setProperty("webdriver(navegador", "diretório do navegador");
        driver = new EdgeDriver();
    }

    @Test
    public void paginaInicial() throws InterruptedException, AWTException {
        driver.get("http://localhost:8080/");
    }


    @io.cucumber.java.pt.Dado("^que estou na tela inicial$")
    public void queEstouNaTelaInicial() {
    }

    @io.cucumber.java.pt.Quando("^clico na opção Colaboradores$")
    public void clicoNaOpçãoColaboradores() {
    }

    @io.cucumber.java.pt.E("^adiciono no campo colaborador$")
    public void adicionoNoCampoColaborador() {
    }

    @io.cucumber.java.pt.E("^preencho nome, data de nascimento, CPF e descrição da função$")
    public void preenchoNomeDataDeNascimentoCPFEDescriçãoDaFunção() {
    }

    @io.cucumber.java.pt.E("^clico em salvar o colaborador$")
    public void clicoEmSalvarOColaborador() {
    }

    @io.cucumber.java.pt.Entao("^o banco de dados armazena os dados lançados$")
    public void oBancoDeDadosArmazenaOsDadosLançados() {
    }
}
