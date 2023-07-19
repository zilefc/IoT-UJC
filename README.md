# Mini curso de IoT com Esp-01, firebase, vercel e Arduino
Repositorio Contendo ficheiros e codigo usado no Workshop ministrado na Universidade Joaquim Chissano por Frederico Zile no ambito do projecto www.tmeeducation.com

No presente projecto controla-se uma lampada usando uma pagina web construida com HTML e CSS. O Esp8266 é usado para fazer a varedura numa Real Time database do Firebase (Google) e função da resposta liga ou desliga uma lampada.
![image](https://user-images.githubusercontent.com/46302322/226078425-2feff363-947a-4093-9504-cd5c0c0ee367.png)


Se estiver a ter problemas de conexao ao firebase tente fazer o seguinte:
1. Vai ate: "Arduino/libraries/firebase-arduino-master/src/FirebaseHttpClient.h" (Pode abrir com notepad ou vsCode)
2.  Mude o parametro: kFirebaseFingerprint[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
3.  Para o passo anterior deves verificar qual eh o fingerprint actual em https://www.grc.com/fingerprints.htm
4.  Use test.firebaseio.com para obter o figerprint
