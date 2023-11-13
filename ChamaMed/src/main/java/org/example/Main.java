package ChamadasLeitos.chamadas;

import ChamadasLeitos.chamadas.Controller.C_Interruptor;
import ChamadasLeitos.chamadas.Model.M_Interruptor;
import ChamadasLeitos.chamadas.Model.M_Registro;
import ChamadasLeitos.chamadas.Repository.R_Registro;
import ChamadasLeitos.chamadas.Service.S_Interruptor;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import com.fazecast.jSerialComm.*;

import java.util.Optional;


@SpringBootApplication
public class ChamadasApplication {



	public static void main(String[] args) {
		SpringApplication.run(ChamadasApplication.class, args);




	SerialPort sp = SerialPort.getCommPort("dev/cu.usbserial-1120");
        sp.openPort();
        sp.setBaudRate(9600);

	String memoriaBuffer = "";

	boolean porta2 = false;
	boolean porta3 = false;
	boolean porta4 = false;
	boolean porta5 = false;
	boolean porta6 = false;

		try {
			boolean porta2EstadoAnterior = false;
			boolean porta3EstadoAnterior = false;
			boolean porta4EstadoAnterior = false;
			boolean porta5EstadoAnterior = false;
			boolean porta6EstadoAnterior = false;

			while (true) {
				if (sp.bytesAvailable() > 0) {
					byte[] leituraBuffer = new byte[sp.bytesAvailable()];
					int qtdeLido = sp.readBytes(leituraBuffer, leituraBuffer.length);
					String dadoRecebido = new String(leituraBuffer);

					memoriaBuffer += dadoRecebido;

					if (memoriaBuffer.contains("\n")) {
						String[] linhas = memoriaBuffer.split("\n");
						for (String linha : linhas) {
							linha = linha.trim();

							// Verifique se houve mudanças nas portas antes de enviar informações
							if ((linha.equals("porta2Lig") && porta2EstadoAnterior != true) ||
									(linha.equals("porta2Des") && porta2EstadoAnterior != false)) {
								porta2 = !porta2;
								System.out.println("porta 2 " + (porta2 ? "ligada" : "desligada"));
								S_Interruptor.alterarEstado("601 A");
								porta2EstadoAnterior = porta2;
							}

							if ((linha.equals("porta3Lig") && porta3EstadoAnterior != true) ||
									(linha.equals("porta3Des") && porta3EstadoAnterior != false)) {
								porta3 = !porta3;
								System.out.println("porta 3 " + (porta3 ? "ligada" : "desligada"));
								S_Interruptor.alterarEstado("601 B");
								porta3EstadoAnterior = porta3;
							}

							if ((linha.equals("porta4Lig") && porta4EstadoAnterior != true) ||
									(linha.equals("porta4Des") && porta4EstadoAnterior != false)) {
								porta4 = !porta4;
								System.out.println("porta 4 " + (porta4 ? "ligada" : "desligada"));
								S_Interruptor.alterarEstado("601 C");
								porta4EstadoAnterior = porta4;
							}

							if ((linha.equals("porta5Lig") && porta5EstadoAnterior != true) ||
									(linha.equals("porta5Des") && porta5EstadoAnterior != false)) {
								porta5 = !porta5;
								System.out.println("porta 5 " + (porta5 ? "ligada" : "desligada"));
								S_Interruptor.alterarEstado("601 D");
								porta5EstadoAnterior = porta5;
							}

							if ((linha.equals("porta6Lig") && porta6EstadoAnterior != true) ||
									(linha.equals("porta6Des") && porta6EstadoAnterior != false)) {
								porta6 = !porta6;
								System.out.println("porta 6 " + (porta6 ? "ligada" : "desligada"));
								S_Interruptor.alterarEstado("Emergência 601");
								porta6EstadoAnterior = porta6;
							}
						}

						memoriaBuffer = "";
					}
				}
				Thread.sleep(500);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		sp.closePort();

	}
}

