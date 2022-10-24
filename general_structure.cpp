Structure générale du programme:
(On aura besoin ici des classes Server, User, Channel, Command, Reply)

serv = Server() <- objet de classe Server qui stock l'état général du server, donc ses utilisateurs (classe User) et ses channels (classe Channel)

while(True)
{
	à partir du poll() et du socket, on connait normalement de quel user il s'agit;
	si il est inconnu, c'est un cas particulier (voir plus bas)
	//alice : inconnu = nouveau client ?
	//faire aussi gestion erreur cad si poll renvoie error
	recv(IRC_msg) <- recevoir des données brutes du client
	if (connection d'un nouveau client) <- cas particulier à traiter car le client va envoyer deux commandes et non une seule
	{
		if (valid_request(IRC_msg)) <- regarder si les message NICK et USER sont bien présents avec les bons paramètres

			new_user = User() <- creer un nouvel objet de classe User

			serv.add_user(new_user) <- l'ajouter au serveur

			send(welcome_response) <- envoyer une réponse de bienvenue
		else:
			send(error_response) <- envoyer une réponse d'erreur
	}
	else
	{
		cmd = Command(IRC_msg) <- construire un objet de classe Command en parsant IRC_msg

		rply = Reply(cmd, user) <- construire un objet de class Reply à partir de l'objet cmd et des données du User concerné

		send(rply.intostr()) <- renvoyer une réponse à la commande en données brutes

		serv.update(cmd) <- le serveur met à jour les users et les channels de façon appropriées	
	}
	//sortir du while
}
