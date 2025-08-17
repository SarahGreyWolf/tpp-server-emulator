#include <std_include.hpp>

#include "cmd_get_combat_deploy_list.hpp"

namespace emulator::tpp
{
nlohmann::json cmd_get_combat_deploy_list::execute(nlohmann::json &data, const std::optional<database::players::player> &player)
{
    nlohmann::json result;

    nlohmann::json mission_list[1];
    int count = 0;

    for (int i = 0; i < 1; i++)
    {
        nlohmann::json mission;
        mission["armored_max"] = 0;
        mission["armored_min"] = 0;
        mission["battle_gear"] = 1;
        mission["car_max"] = 0;
        mission["car_min"] = 0;
        mission["category"] = 7;
        mission["combat_count"] = 20;
        mission["combat_rank"] = 7;
        mission["dead_rate"] = 0;
        mission["is_campaign"] = 1;
        mission["latitude"] = -18300;
        mission["longitude"] = 15500;
        mission["max_dead_rate"] = 100;
        mission["min_dead_rate"] = 0;
        mission["max_win_rate"] = 100;
        mission["min_win_rate"] = 0;
        mission["mission_id"] = 407;
        mission["name_key"] = mission["category"];

        nlohmann::json rewards[2];
        rewards[0]["bottom_type"] = 1;
        rewards[0]["mecha_type"] = 0;
        rewards[0]["rate"] = 1000000;
        rewards[0]["section"] = 0;
        rewards[0]["type"] = 1;
        rewards[0]["value"] = 2100000;

        rewards[1]["bottom_type"] = 12;
        rewards[1]["mecha_type"] = 0;
        rewards[1]["rate"] = 1000000;
        rewards[1]["section"] = 0;
        rewards[1]["type"] = 12;
        rewards[1]["value"] = 500;

        mission["primary_reward"] = rewards;
        mission["reward"] = mission["primary_reward"][0]["type"];
        mission["section"] = 4;
        mission["section_count"] = 20;
        mission["section_rank"] = 2;
        mission["seed"] = 28980;
        mission["server_text_id"] = 0;
        mission["tank_max"] = 0;
        mission["tank_min"] = 0;

        nlohmann::json team;
        team["armored"] = 0;
        team["battle_gear"] = 0;
        team["car"] = 0;
        team["combat_count"] = 0;
        team["combat_rank_bottom"] = 0;
        team["combat_rank_top"] = 0;
        team["dead_rate"] = 0;
        team["is_valid"] = 0;
        team["mission_id"] = 0;
        team["seed"] = 0;
        team["staff_power"] = 0;
        team["sub_count"] = 0;
        team["sub_rank_bottom"] = 0;
        team["sub_rank_top"] = 0;
        team["tank"] = 0;
        team["team_id"] = 0;
        team["team_power"] = 0;
        team["time"] = 0;
        team["truck"] = 0;
        team["walker_gear"] = 0;
        team["win_rate"] = 0;

        mission["team"] = team;
        mission["time"] = 1;
        mission["time_random"] = 0;
        mission["truck_max"] = 0;
        mission["truck_min"] = 0;
        mission["walker_gear_max"] = 0;
        mission["walker_gear_min"] = 0;
        mission["win_rate"] = 100;
        mission_list[count++] = mission;
    }

    result["result"] = "NOERR";
    result["mission_list"] = mission_list;
    result["mission_num"] = count;

    return result;
}
} // namespace emulator::tpp
