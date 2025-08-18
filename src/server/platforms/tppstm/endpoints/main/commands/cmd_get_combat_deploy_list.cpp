#include <std_include.hpp>

#include "cmd_get_combat_deploy_list.hpp"

#include "database/models/combat_ops.hpp"
#include "database/models/ops_team.hpp"

namespace emulator::tpp {

void create_empty_team(nlohmann::json &team) {
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
}

nlohmann::json cmd_get_combat_deploy_list::execute(
    nlohmann::json &data,
    const std::optional<database::players::player> &player) {
    nlohmann::json result;

    auto ops = database::combat_ops::get_ops();

    nlohmann::json mission_list[100];
    int count = 0;

    for (database::combat_ops::combat_ops op : ops) {
        nlohmann::json mission;

        mission["armored_max"] = op.get_armored_max();
        mission["armored_min"] = op.get_armored_min();
        mission["battle_gear"] = op.get_battle_gear();
        mission["car_max"] = op.get_car_max();
        mission["car_min"] = op.get_car_min();
        mission["category"] = op.get_category();
        mission["combat_count"] = op.get_combat_count();
        mission["combat_rank"] = op.get_combat_rank();
        mission["dead_rate"] = op.get_dead_rate();
        mission["is_campaign"] = op.get_is_campaign();
        mission["latitude"] = op.get_latitude();
        mission["longitude"] = op.get_longitude();
        mission["max_dead_rate"] = op.get_max_dead_rate();
        mission["min_dead_rate"] = op.get_min_dead_rate();
        mission["max_win_rate"] = op.get_max_win_rate();
        mission["min_win_rate"] = op.get_min_win_rate();
        mission["mission_id"] = op.get_mission_id();
        mission["name_key"] = mission["category"];

        mission["primary_reward"] =
            nlohmann::json::parse(op.get_primary_reward());
        mission["reward"] = mission["primary_reward"][0]["type"];
        mission["section"] = op.get_section();
        mission["section_count"] = op.get_section_count();
        mission["section_rank"] = op.get_section_rank();
        mission["seed"] = op.get_seed();
        mission["server_text_id"] = op.get_server_text_id();
        mission["tank_max"] = op.get_tank_max();
        mission["tank_min"] = op.get_tank_min();

        nlohmann::json team;
        if (op.get_team() == NULL) {
            create_empty_team(team);
        } else {
            auto ops_team_opt = database::ops_team::find(op.get_team());
            if (ops_team_opt.has_value()) {
                database::ops_team::ops_team ops_team = ops_team_opt.value();
                team["armored"] = ops_team.get_armored();
                team["battle_gear"] = ops_team.get_battle_gear();
                team["car"] = ops_team.get_car();
                team["combat_count"] = ops_team.get_combat_count();
                team["combat_rank_bottom"] = ops_team.get_combat_rank_bottom();
                team["combat_rank_top"] = ops_team.get_combat_rank_top();
                team["dead_rate"] = ops_team.get_dead_rate();
                team["is_valid"] = ops_team.get_is_valid();
                team["mission_id"] = ops_team.get_mission_id();
                team["seed"] = ops_team.get_seed();
                team["staff_power"] = ops_team.get_staff_power();
                team["sub_count"] = ops_team.get_sub_count();
                team["sub_rank_bottom"] = ops_team.get_sub_rank_bottom();
                team["sub_rank_top"] = ops_team.get_sub_rank_top();
                team["tank"] = ops_team.get_tank();
                team["team_id"] = ops_team.get_team_id();
                team["team_power"] = ops_team.get_team_power();
                team["time"] = ops_team.get_time();
                team["truck"] = ops_team.get_truck();
                team["walker_gear"] = ops_team.get_walker_gear();
                team["win_rate"] = ops_team.get_win_rate();
            } else {
                create_empty_team(team);
            }
        }

        mission["team"] = team;
        mission["time"] = op.get_time();
        mission["time_random"] = op.get_time_random();
        mission["truck_max"] = op.get_truck_max();
        mission["truck_min"] = op.get_truck_min();
        mission["walker_gear_max"] = op.get_walker_gear_max();
        mission["walker_gear_min"] = op.get_walker_gear_min();
        mission["win_rate"] = op.get_win_rate();
        mission_list[count++] = mission;
    }

    result["result"] = "NOERR";
    result["mission_list"] = mission_list;
    result["mission_num"] = ops.size();

    return result;
}
} // namespace emulator::tpp
