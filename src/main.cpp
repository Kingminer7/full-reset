#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        if (PlayLayer::get()->m_isPlatformer) return;

        auto myButton = CCMenuItemExt::createSpriteExtraWithFrameName("GJ_replayFullBtn_001.png", 1.f, [this](auto){
            PlayLayer::get()->fullReset();
            onResume(nullptr);
        });
        myButton->setID("full-restart-button"_spr);

        auto menu = this->getChildByID("center-button-menu");
        menu->addChild(myButton);
        myButton->setOrderOfArrival(menu->getChildByID("practice-button")->getOrderOfArrival() - 1);
        menu->updateLayout();
    }
};
