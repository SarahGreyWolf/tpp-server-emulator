#pragma once

#include "../database.hpp"

#include "combat_ops.hpp"
#include "fobs.hpp"
#include "player_data.hpp"
#include "players.hpp"

#include "utils/tpp.hpp"

namespace database::ops_team {

class ops_team {
public:
    DEFINE_FIELD(id, sqlpp::integer_unsigned);
    DEFINE_FIELD(armored, sqlpp::integer_unsigned);
    DEFINE_FIELD(battle_gear, sqlpp::integer_unsigned);
    DEFINE_FIELD(car, sqlpp::integer_unsigned);
    DEFINE_FIELD(combat_count, sqlpp::integer_unsigned);
    DEFINE_FIELD(combat_rank_bottom, sqlpp::integer_unsigned);
    DEFINE_FIELD(combat_rank_top, sqlpp::integer_unsigned);
    DEFINE_FIELD(dead_rate, sqlpp::integer_unsigned);
    DEFINE_FIELD(is_valid, sqlpp::integer_unsigned);
    DEFINE_FIELD(mission_id, sqlpp::integer_unsigned);
    DEFINE_FIELD(seed, sqlpp::integer_unsigned);
    DEFINE_FIELD(staff_power, sqlpp::integer_unsigned);
    DEFINE_FIELD(sub_count, sqlpp::integer_unsigned);
    DEFINE_FIELD(sub_rank_bottom, sqlpp::integer_unsigned);
    DEFINE_FIELD(sub_rank_top, sqlpp::integer_unsigned);
    DEFINE_FIELD(tank, sqlpp::integer_unsigned);
    DEFINE_FIELD(team_power, sqlpp::integer_unsigned);
    DEFINE_FIELD(time, sqlpp::integer_unsigned);
    DEFINE_FIELD(truck, sqlpp::integer_unsigned);
    DEFINE_FIELD(walker_gear, sqlpp::integer_unsigned);
    DEFINE_FIELD(win_rate, sqlpp::integer_unsigned);
    DEFINE_FIELD(player_id, sqlpp::integer_unsigned);
    DEFINE_TABLE(ops_team, id_field_t, armored_field_t, battle_gear_field_t,
                 car_field_t, combat_count_field_t, combat_rank_bottom_field_t,
                 combat_rank_top_field_t, dead_rate_field_t, is_valid_field_t,
                 mission_id_field_t, seed_field_t, staff_power_field_t,
                 sub_count_field_t, sub_rank_bottom_field_t,
                 sub_rank_top_field_t, tank_field_t, team_power_field_t,
                 time_field_t, truck_field_t, walker_gear_field_t,
                 win_rate_field_t, player_id_field_t);

    inline static table_t table;

    template <typename... Args>
    ops_team(const sqlpp::result_row_t<Args...> &row) {
        this->team_id_ = row.id;
        this->armored_ = row.armored;
        this->battle_gear_ = row.battle_gear;
        this->car_ = row.car;
        this->combat_count_ = row.combat_count;
        this->combat_rank_bottom_ = row.combat_rank_bottom;
        this->combat_rank_top_ = row.combat_rank_top;
        this->dead_rate_ = row.dead_rate;
        this->is_valid_ = row.is_valid;
        this->mission_id_ = row.mission_id;
        this->seed_ = row.seed;
        this->staff_power_ = row.staff_power;
        this->sub_count_ = row.sub_count;
        this->sub_rank_bottom_ = row.sub_rank_bottom;
        this->sub_rank_top_ = row.sub_rank_top;
        this->tank_ = row.tank;
        this->team_power_ = row.team_power;
        this->time_ = row.time;
        this->truck_ = row.truck;
        this->walker_gear_ = row.walker_gear;
        this->win_rate_ = row.win_rate;
        this->player_id_ = row.player_id;
    }

    GET_FIELD_H(std::uint64_t, team_id); // The id of the team (possibly a
                                         // mission_teams table primary_key?)
    GET_FIELD_H(std::uint64_t, armored); // Number of armored vehicles deployed
    GET_FIELD_H(std::uint64_t, battle_gear);  // Is battle gear deployed
    GET_FIELD_H(std::uint64_t, car);          // Number of cars deployed
    GET_FIELD_H(std::uint64_t, combat_count); // Deployed Main Combat Unit Size
    GET_FIELD_H(std::uint64_t,
                combat_rank_bottom); // When a range of ranks (like S+ - S) this
                                     // is the lowest rank
    GET_FIELD_H(std::uint64_t,
                combat_rank_top); // The highest rank deployed (see Staff Ranks
                                  // (take rank and add 1))
    GET_FIELD_H(std::uint64_t, dead_rate); // ????
    GET_FIELD_H(std::uint64_t,
                is_valid); // When value is 1, the mission is marked as
                           // currently active for the client
    GET_FIELD_H(std::uint64_t,
                mission_id); // Matches the op mission_id, leading credence to
                             // database relations, maybe
    GET_FIELD_H(std::uint64_t, seed); // Seems to be 0 regardless of if it's an
                                      // active team or not, and doesn't match
    GET_FIELD_H(std::uint64_t, staff_power); // Total Fighting Ability for this
                                             // team (How it calculates Success
    GET_FIELD_H(std::uint64_t, sub_count);   // Deployed Supporting Unit Size
    GET_FIELD_H(std::uint64_t,
                sub_rank_bottom); // When a range of ranks (like S+ - S) this is
                                  // the lowest rank deployed
    GET_FIELD_H(std::uint64_t,
                sub_rank_top); // The highest rank deployed (see Staff Ranks
                               // (take rank and add 1))
    GET_FIELD_H(std::uint64_t, tank);       // Number of tanks deployed
    GET_FIELD_H(std::uint64_t, team_power); // Seems to match staff_power
    GET_FIELD_H(std::uint64_t, time);  // Time (in seconds) left of the mission
    GET_FIELD_H(std::uint64_t, truck); // Number of Trucks deployed
    GET_FIELD_H(std::uint64_t, walker_gear); // Number of walker gear deployed
    GET_FIELD_H(std::uint64_t,
                win_rate); // Unknown, doesn't match the missions win rate,
                           // maybe is their success level
    GET_FIELD_H(std::uint64_t, player_id);
};
} // namespace database::ops_team