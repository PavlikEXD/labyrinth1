#include "player.h"
#include "bot.h"
#include "string"

int main()
{

	srand((unsigned)time(NULL));

	Player player;
	Bot bot;
	bot.iPlayer.moveField(0, 510);
	bot.Enemy.moveField(0, 510);
	bool winBots = 0;

	//cout<<player.myMove.at(0).getPlace();
	int Game = 0;
	Event event;
	Vector2i position;
	int counterWalls = 40;


	//text
	Font font;//шрифт 
	font.loadFromFile("Giger.ttf");//передаем нашему шрифту файл шрифта
	Text text("Press enter for game", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setFillColor(Color::Blue);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый
	text.setPosition(400, 10);

	/////////////

	//map
	Texture mapTexture;
	Sprite mapSprite;
	mapTexture.loadFromFile("images/map.png");
	mapSprite.setTexture(mapTexture);

	//////////////////

	//help

	Texture helpTexture;
	Sprite helpSprite;
	helpTexture.loadFromFile("images/help.png");
	helpSprite.setTexture(helpTexture);
	helpSprite.setTextureRect(IntRect(0, 0, 456, 75));
	helpSprite.setPosition(300, 200);


	sf::RenderWindow window(VideoMode(1200, 800), "labyrinth", Style::Fullscreen);

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();

			switch (event.type) {


			case Event::MouseButtonPressed: {
				if (event.mouseButton.button == sf::Mouse::Left); {
					position = Mouse::getPosition();
					if (position.x > 950 && position.x < 975 && position.y>0 && position.y < 28)window.close();
					else
						if (Game == 2 && counterWalls) {

							counterWalls += 40 * player.wallMaking(position);
							helpSprite.setTextureRect(IntRect(counterWalls, 0, 40, 20));
							if (!counterWalls) {
								text.setString("You                     finish:                         Enemy");
								helpSprite.setTextureRect(IntRect(40, 0, 40, 20));
							}
						}
						else if (Game == 2) {
							player.setFinish(position);
							helpTexture.loadFromFile("images/help.png");
							helpSprite.setTextureRect(IntRect(0, 75, 456, 75));
							helpSprite.setPosition(300, 200);
							Game++;

						}
					break;
				}
			}
			case Event::KeyReleased: {
				if (event.key.code == Keyboard::Return) //указываешь кнопку
				{
					if (!Game) {
						Game = 1;

						text.setString("You                                                    Enemy");
						text.setPosition(235, 10);
						text.setStyle(Text::Bold);
					}
					else if (Game == 1) {
						Game = 2;
						text.setString("You                     walls:                         Enemy");
						helpTexture.loadFromFile("images/numbers.png");
						helpSprite.setTexture(helpTexture);
						helpSprite.move(220, -190);
						counterWalls = 16 * 40;
						helpSprite.setTextureRect(IntRect(counterWalls, 0, 40, 20));

					}
					if (Game == 3) {
						text.setString("You                   Good luck                        Enemy");
						helpSprite.setPosition(1500, 1500);
						Game++;
					}
				}
				
				if (Game == 4)
					switch (event.key.code)
					{
					case  Keyboard::W: {
						if (player.Enemy.isOpen(player.step.getPlace(), UP)) {
							if (!(bot.iPlayer.isOpen(player.step.getPlace(), UP))) {
								player.Enemy.setOpenness(0, player.step.getPlace(), UP);
								if (bot.going(player.iPlayer)) {
									Game++;
									helpSprite.setTextureRect(IntRect(0, 240, 410, 80));
									helpSprite.setPosition(300, 200);
								}
							}
							else player.going(UP);
						}
						break;
					}
					case Keyboard::A: {
						if (player.Enemy.isOpen(player.step.getPlace(), LEFT)) {
							if (!(bot.iPlayer.isOpen(player.step.getPlace(), LEFT))) {
								player.Enemy.setOpenness(0, player.step.getPlace(), LEFT);
								if (bot.going(player.iPlayer)) {
									Game++;
									helpSprite.setTextureRect(IntRect(0, 240, 410, 80));
									helpSprite.setPosition(300, 200);
								}
							}
							else player.going(LEFT);
						}
						break;
					}
					case Keyboard::S: {
						if (player.Enemy.isOpen(player.step.getPlace(), DOWN)) {
							if (!(bot.iPlayer.isOpen(player.step.getPlace(), DOWN))) {
								player.Enemy.setOpenness(0, player.step.getPlace(), DOWN);
								if (bot.going(player.iPlayer)) {
									Game++;
									helpSprite.setTextureRect(IntRect(0, 240, 410, 80));
									helpSprite.setPosition(300, 200);
								}
							}
							else player.going(DOWN);

						}
						break;
					}
					case Keyboard::D: {
						if (player.Enemy.isOpen(player.step.getPlace(), RIGHT)) {
							if (!(bot.iPlayer.isOpen(player.step.getPlace(), RIGHT))) {
								player.Enemy.setOpenness(0, player.step.getPlace(), RIGHT);
								if (bot.going(player.iPlayer)) {
									Game++;
									helpSprite.setTextureRect(IntRect(0, 240, 410, 80));
									helpSprite.setPosition(300, 200);
								}

							}
							else player.going(RIGHT);

						}
						break;
					}
					}
				if (bot.iPlayer.isFinish(player.step.getPlace()) && Game == 4) {
					helpSprite.setTextureRect(IntRect(0, 165, 350, 60));
					helpSprite.setPosition(300, 200);
					Game++;
				}

			}
			default:
				break;
			}
		}

		window.clear();
		window.draw(mapSprite);
		window.draw(text);
		for (int i = 0; i < 25; i++) {
			window.draw(player.iPlayer.getSprite(i, LEFT));
			window.draw(player.iPlayer.getSprite(i, UP));
			window.draw(player.iPlayer.getSprite(i, RIGHT));
			window.draw(player.iPlayer.getSprite(i, DOWN));

			window.draw(player.Enemy.getSprite(i, LEFT));
			window.draw(player.Enemy.getSprite(i, UP));
			window.draw(player.Enemy.getSprite(i, RIGHT));
			window.draw(player.Enemy.getSprite(i, DOWN));


			window.draw(bot.iPlayer.getSprite(i, LEFT));
			window.draw(bot.iPlayer.getSprite(i, UP));
			window.draw(bot.iPlayer.getSprite(i, RIGHT));
			window.draw(bot.iPlayer.getSprite(i, DOWN));


			window.draw(bot.Enemy.getSprite(i, LEFT));
			window.draw(bot.Enemy.getSprite(i, UP));
			window.draw(bot.Enemy.getSprite(i, RIGHT));
			window.draw(bot.Enemy.getSprite(i, DOWN));

		}

		if (Game > 3) {
			for_each(bot.myMove.begin(), bot.myMove.end(), [&window](Move a) { window.draw(Move(a.getPlace()).getSprite()); });
			if(bot.garbageMove.size())
			for_each(bot.garbageMove.begin(), bot.garbageMove.end(), [&window](Move a) { window.draw(Move(a.getPlace()).getSprite()); });
			window.draw(player.step.getSprite());
		}
		if (Game) {
			if (Game > 2) window.draw(player.getfinishSprite());
			window.draw(helpSprite);
		}
		
		
		window.display();
	}

	return 0;

	
}