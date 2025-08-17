#pragma once

#include "../database.hpp"

#include "utils/tpp.hpp"

#include "fobs.hpp"
#include "player_data.hpp"
#include "players.hpp"

namespace database::combat_ops {

enum staff_rank {
    rank_e = 0,
    rank_d = 1,
    rank_c = 2,
    rank_b = 3,
    rank_a = 4,
    rank_ap = 5,  // A+
    rank_app = 6, // A++
    rank_s = 7,
    rank_sp = 8, // S+
    rank_spp = 9 // S++
};

enum staff_section {
    section_combat = 1,
    section_research = 2,
    section_base_dev = 3,
    section_support = 4,
    section_intel = 5,
    section_medical = 6
};

enum reward_type {
    reward_gmp = 1,
    // Staff Ranks
    reward_spp = 2, // S++
    reward_sp = 3,  // S+
    reward_s = 4,
    reward_app = 5, // A++
    reward_ap = 6,  // A+
    reward_a = 7,
    reward_b = 8,
    reward_c = 9,
    reward_d = 10,
    reward_e = 11,
    // Materials
    reward_common_metal = 12,
    reward_minor_metal = 13,
    reward_precious_metal = 14,
    reward_fuel = 15,
    reward_biological_material = 16,
    // Plants
    reward_golden_crescent = 17,
    reward_african_peach = 18,
    reward_digital_purpurea = 19,
    reward_digitalis_lutea = 20,
    reward_black_carrot = 21,
    reward_wormwood = 22,
    reward_tarragon = 23,
    reward_haoma = 24,
    reward_missile = 25
};

enum missile_mecha_type {
    miss_liquid_carbon = 0,
    miss_anti_ballistic = 1,
};

enum mission_category {
    cat_far_water = 7,           // "Far Waters Exploitation"
    cat_reconstruct_support = 8, // "Reconstruction Support"
    cat_staff_recruit = 9,       // "Staff Recruitment"
    cat_staff_headhunt = 10,     // "Staff Headhunting"
    cat_plant_gather = 11,       // "Plants Gathering"
    cat_lcm_dev = 12,            // "Join Development: Liquid Carbon Missiles"
    cat_abm_dev = 13             // "Join Development: Anti-Ballistic Missiles"
};

struct reward_t {
    reward_type bottom_type_;
    std::uint64_t mecha_type_;
    std::uint64_t rate_;
    std::uint64_t section_;
    reward_type type_;
    std::uint64_t value_;
};

class combat_ops {
public:
    DEFINE_FIELD(id, sqlpp::integer_unsigned);
    DEFINE_FIELD(armored_max, sqlpp::integer_unsigned);
    DEFINE_FIELD(armored_min, sqlpp::integer_unsigned);
    DEFINE_FIELD(battle_gear, sqlpp::integer_unsigned);
    DEFINE_FIELD(car_max, sqlpp::integer_unsigned);
    DEFINE_FIELD(car_min, sqlpp::integer_unsigned);
    DEFINE_FIELD(category, sqlpp::integer_unsigned);
    DEFINE_FIELD(combat_count, sqlpp::integer_unsigned);
    DEFINE_FIELD(combat_rank, sqlpp::integer_unsigned);
    DEFINE_FIELD(dead_rate, sqlpp::integer_unsigned);
    DEFINE_FIELD(is_campaign, sqlpp::boolean);
    DEFINE_FIELD(latitude, sqlpp::integer_unsigned);
    DEFINE_FIELD(longitude, sqlpp::integer_unsigned);
    DEFINE_FIELD(max_dead_rate, sqlpp::integer_unsigned);
    DEFINE_FIELD(min_dead_rate, sqlpp::integer_unsigned);
    DEFINE_FIELD(max_win_rate, sqlpp::integer_unsigned);
    DEFINE_FIELD(min_win_rate, sqlpp::integer_unsigned);
    DEFINE_FIELD(primary_reward, sqlpp::text);
    DEFINE_FIELD(name_key, sqlpp::integer_unsigned);
    DEFINE_FIELD(reward, sqlpp::integer_unsigned);
    DEFINE_FIELD(section, sqlpp::integer_unsigned);
    DEFINE_FIELD(section_count, sqlpp::integer_unsigned);
    DEFINE_FIELD(section_rank, sqlpp::integer_unsigned);
    DEFINE_FIELD(seed, sqlpp::integer_unsigned);
    DEFINE_FIELD(server_text_id, sqlpp::integer_unsigned);
    DEFINE_FIELD(tank_max, sqlpp::integer_unsigned);
    DEFINE_FIELD(tank_min, sqlpp::integer_unsigned);
    DEFINE_FIELD(team_id, sqlpp::integer_unsigned);
    DEFINE_FIELD(time, sqlpp::integer_unsigned);
    DEFINE_FIELD(time_random, sqlpp::integer_unsigned);
    DEFINE_FIELD(truck_max, sqlpp::integer_unsigned);
    DEFINE_FIELD(truck_min, sqlpp::integer_unsigned);
    DEFINE_FIELD(walker_gear_max, sqlpp::integer_unsigned);
    DEFINE_FIELD(walker_gear_min, sqlpp::integer_unsigned);
    DEFINE_FIELD(win_rate, sqlpp::integer_unsigned);
    DEFINE_TABLE(combat_ops, id_field_t, armored_max_field_t,
                 armored_min_field_t, battle_gear_field_t, car_max_field_t,
                 car_min_field_t, category_field_t, combat_count_field_t,
                 combat_rank_field_t, dead_rate_field_t, is_campaign_field_t,
                 latitude_field_t, longitude_field_t, max_dead_rate_field_t,
                 min_dead_rate_field_t, max_win_rate_field_t,
                 min_win_rate_field_t, primary_reward_field_t, name_key_field_t,
                 reward_field_t, section_field_t, section_count_field_t,
                 section_rank_field_t, seed_field_t, server_text_id_field_t,
                 tank_max_field_t, tank_min_field_t, team_id_field_t,
                 time_field_t, time_random_field_t, truck_max_field_t,
                 truck_min_field_t, walker_gear_max_field_t,
                 walker_gear_min_field_t, win_rate_field_t);

    inline static table_t table;

    template <typename... Args>
    combat_ops(const sqlpp::result_row_t<Args...> &row) {
        this->mission_id_ = row.id;
        this->armored_max_ = row.armored_max;
        this->armored_min_ = row.armored_min;
        this->battle_gear_ = row.battle_gear;
        this->car_max_ = row.car_max;
        this->car_min_ = row.car_min;
        this->category_ = row.category;
        this->combat_count_ = row.combat_count;
        this->combat_rank_ = row.combat_rank;
        this->dead_rate_ = row.dead_rate;
        this->is_campaign_ = row.is_campaign;
        this->latitude_ = row.latitude;
        this->longitude_ = row.longitude;
        this->max_dead_rate_ = row.max_dead_rate;
        this->min_dead_rate_ = row.min_dead_rate;
        this->max_win_rate_ = row.max_win_rate;
        this->min_win_rate_ = row.min_win_rate;
        this->name_key_ = row.name_key;
        this->primary_reward_ = row.primary_reward;
        this->reward_ = row.reward;
        this->section_ = row.section;
        this->section_count_ = row.section_count;
        this->section_rank_ = row.section_rank;
        this->seed_ = row.seed;
        this->server_text_id_ = row.server_text_id;
        this->tank_max_ = row.tank_max;
        this->tank_min_ = row.tank_min;
        this->team_ = row.team_id;
        this->time_ = row.time;
        this->time_random_ = row.time_random;
        this->truck_max_ = row.truck_max;
        this->truck_min_ = row.truck_min;
        this->walker_gear_max_ = row.walker_gear_max;
        this->walker_gear_min_ = row.walker_gear_min;
        this->win_rate_ = row.win_rate;
    }

    GET_FIELD_H(std::uint64_t, mission_id);
    GET_FIELD_H(std::uint32_t, armored_max);
    GET_FIELD_H(std::uint32_t, armored_min);
    GET_FIELD_H(std::uint32_t, battle_gear);
    GET_FIELD_H(std::uint32_t, car_max);
    GET_FIELD_H(std::uint32_t, car_min);
    GET_FIELD_H(std::uint32_t, category);
    GET_FIELD_H(std::uint32_t, combat_count);
    GET_FIELD_H(std::uint32_t, combat_rank);
    GET_FIELD_H(std::uint32_t, dead_rate);
    GET_FIELD_H(bool, is_campaign);
    GET_FIELD_H(std::int32_t, latitude);
    GET_FIELD_H(std::int32_t, longitude);
    GET_FIELD_H(std::uint32_t, max_dead_rate);
    GET_FIELD_H(std::uint32_t, min_dead_rate);
    GET_FIELD_H(std::uint32_t, max_win_rate);
    GET_FIELD_H(std::uint32_t, min_win_rate);
    GET_FIELD_H(std::uint32_t, name_key);
    GET_FIELD_H(std::string, primary_reward);
    GET_FIELD_H(std::uint32_t, reward);
    GET_FIELD_H(std::uint32_t, section);
    GET_FIELD_H(std::uint32_t, section_count);
    GET_FIELD_H(std::uint32_t, section_rank);
    GET_FIELD_H(std::uint32_t, seed);
    GET_FIELD_H(std::uint32_t, server_text_id);
    GET_FIELD_H(std::uint32_t, tank_max);
    GET_FIELD_H(std::uint32_t, tank_min);
    GET_FIELD_H(std::uint64_t, team);
    GET_FIELD_H(std::uint32_t, time);
    GET_FIELD_H(std::uint32_t, time_random);
    GET_FIELD_H(std::uint32_t, truck_max);
    GET_FIELD_H(std::uint32_t, truck_min);
    GET_FIELD_H(std::uint32_t, walker_gear_max);
    GET_FIELD_H(std::uint32_t, walker_gear_min);
    GET_FIELD_H(std::uint32_t, win_rate);
};

std::vector<combat_ops> get_ops();
} // namespace database::combat_ops