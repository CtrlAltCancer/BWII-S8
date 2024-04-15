Effettuiamo delle SQL injection sul sito.

sql-1.png e sql-2
%' and 1=0 union select null, table_name from information_schema.tables #
Con questo comando riusciamo a vedere le tabelle disponibili nel database, utilizzando lo schema di informazioni (information_schema.tables).
Tra quelle disponibili, troviamo infatti users, che andremo a manipolare tramite ulteriori injection.

sql-3
%' and 1=0 union select table_name, column_name from information_schema.columns where table_name = 'users' #
Infatti così riusciamo a trovare i dati che vengono conservati degli users registrati nel sito.
Tra quelli presenti, ciò che interessa a noi è il campo password.

sql-4
%' union select user, password from users#
Possiamo implicare che l'account di Gordon Brown sia gordonb, e che la password e99a18c428cb38d5f260853678922e03 sia un hash dell'effettiva password. Salviamo questi dati e tentiamo di recuperare la stringa originale.

hash-to-pwd
John the Ripper è un popolare strumento di cracking delle password. Questo comando viene utilizzato per eseguire un bruteforce attack, o di dizionario per cercare di recuperare le password da un file hash MD5.
(Le password in questione sono già state decodificate nell'esercizio S6L5, di conseguenza, John The Ripper ha dato in output che non c'erano nuovi hash decodificati.)
Con --show -format=Raw-MD5 vediamo le password decodificate. In questo caso, la password di Gordon risulta essere abc123.

login-attempt
Eseguiamo un tentativo di login con le sue credenziali.

login-ok
Come indicato dal sito, "Login effettuato con successo come gordonb."