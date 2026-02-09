#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        if (PlayLayer::get()->m_isPlatformer) return;

        auto myButton = CCMenuItemExt::createSpriteExtraWithFrameName("GJ_replayFullBtn_001.png", 1.f, [this](auto){
	    auto pl = PlayLayer::get();
	    auto isPrac = pl->m_isPracticeMode;
            pl->fullReset();
	    if (isPrac && !Mod::get()->getSettingValue<bool>("reset-prac")) pl->togglePracticeMode(true);
            onResume(nullptr);
        });
        myButton->setID("full-restart-button"_spr);

        auto menu = this->getChildByID("center-button-menu");
        menu->addChild(myButton);
        myButton->setOrderOfArrival(menu->getChildByID("practice-button")->getOrderOfArrival() - 1);
        menu->updateLayout();
    }
};
