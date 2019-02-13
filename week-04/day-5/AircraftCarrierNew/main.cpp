#include <iostream>
#include "F35.h"
#include "F16.h"
#include "Carrier.h"

int main()
{
    F16 aircraft;
    F16 aircraft5;
    F35 aircraft2;
    F35 aircraft3;
    F35 aircraft4;

    F16 aircraft2_0;
    F35 aircraft2_1;
    F35 aircraft2_2;
    F35 aircraft2_3;
    F35 aircraft2_4;


    //std::cout << aircraft.refill(100) << std::endl;
    //std::cout << aircraft.refill(90) << std::endl;

    Carrier carrier(200, 5000);

    carrier.add(&aircraft);
    carrier.add(&aircraft2);
    carrier.add(&aircraft3);
    carrier.add(&aircraft4);
    carrier.add(&aircraft5);

    carrier.fill();

    Carrier carrier2(2000, 5000);

    carrier2.add(&aircraft2_0);
    carrier2.add(&aircraft2_1);
    carrier2.add(&aircraft2_2);
    carrier2.add(&aircraft2_3);
    carrier2.add(&aircraft2_4);


    /* std::cout << aircraft.getCurrentAmmo() << std::endl;
    std::cout << aircraft2.getCurrentAmmo() << std::endl;
    std::cout << aircraft3.getCurrentAmmo() << std::endl;
    std::cout << aircraft4.getCurrentAmmo() << std::endl;
    std::cout << aircraft5.getCurrentAmmo() << std::endl;

    std::cout << carrier.getCarrierAmmo() << std::endl;
     */
    carrier.fight(carrier2);

    std::cout << carrier2.getHP() << std::endl;

    carrier2.fight(carrier);

    std::cout << carrier.getHP() << std::endl;
    carrier.fill();
    carrier2.fill();
    carrier2.fight(carrier);
    std::cout << carrier.getStatus() << std::endl;
    carrier2.fill();
    carrier2.fight(carrier);
    std::cout << carrier.getStatus() << std::endl;
    return 0;
}